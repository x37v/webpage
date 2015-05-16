---
layout: blog
title: Web Log
---

{% for post in site.posts %}
<div markdown="1" class="post">

<div class="heading" markdown="1">
<div class="title" markdown="1">
## [{{ post.title }}]({{ post.url | prepend: site.baseurl }})
</div>
<div class="date" markdown="1">
{{ post.date | date: "%b %-d, %Y" }}
</div>
</div>

<div class="content" markdown="1">
{{ post.excerpt | markdownize }}
{: .post-excerpt} 

[read more]({{ post.url | prepend: site.baseurl }})
<!-- {{ post.tags | join: ', '}} -->
</div>

</div>

{% endfor %}
