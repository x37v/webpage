#include "jackaudioio.hpp"
#define MIN(x,y) ((x) < (y) ? (x) : (y))

class TestJack: public JackCpp::AudioIO {
  public:
    // Your audio callback. All audio processing goes in this function.
    virtual int audioCallback(jack_nframes_t nframes, 
        audioBufVector inBufs,
        audioBufVector outBufs){
      for(unsigned int i = 0; i < MIN(inBufs.size(),outBufs.size()); i++){
        // A simple example: copy the input to the output.
        for(unsigned int j = 0; j < nframes; j++)
          outBufs[i][j] = inBufs[i][j];
      }
      //0 on success
      return 0;
    }
    TestJack() :
      JackCpp::AudioIO("jackcpp-test", 2,2){
    }
};

int main(){
  // initial ports from constructor created here.
  TestJack * t = new TestJack;
  t->start();  // activate the client

  //connect our ports to physical ports
  t->connectToPhysical(0,0);    // connects this client out port 0 to physical destination port 0
  t->connectToPhysical(1,1);    // connects this client out port 1 to physical destination port 1
  t->connectFromPhysical(0,0);  // connects this client in port 0 to physical source port 0
  t->connectFromPhysical(1,1);  // connects this client in port 1 to physical source port 1

  sleep(20);    // sleep to allow the callback to run for 20 seconds.
  t->close();  // stop client.
  delete t;  // always clean up after yourself.
  exit(0);
}
