---
layout: default
title: x37v blog
---

{% for post in site.posts %}
## [{{ post.title }}]({{ post.url | prepend: site.baseurl }})
{{ post.date | date: "%b %-d, %Y" }}

{{ post.excerpt | markdownize }}
{: .post-excerpt} 

[read more]({{ post.url | prepend: site.baseurl }})
<!-- {{ post.tags | join: ', '}} -->

* * *

{% endfor %}

<p class="rss-subscribe">subscribe <a href="{{ "/feed.xml" | prepend: site.baseurl }}">via RSS</a></p>
