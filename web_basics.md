# Web Basics (HTML, CSS, JS)
## Terms
Hypertext Markup Language (HTML): Turing complete language used to create websites and webpages.  Commonly used for formatting and holding information found in a site, not formatting or functionality.
Cascading Style Sheets (CSS): Language used to specify the styling of an html document.  Must be included in the header and works most often with classes and ids.  In charge of style, not content or functionality.
Javascript (JS): Language used to add interactivity and functionality to a website.  Runs client side, i.e. not secure.  Used to change content or styling of a sheet mid execution or can be used to call server side scripting.

## HTML Basics
HTML Documents are used for the foundation of a website.  They do things through tags, which look like ```<>```.  A generic HTML document looks like:
```html
<!DOCTYPE html>
<html>
  <head>
    <link rel="stylesheet" href="style.css" />
    <title>My page</title>
  </head>
  <body>
    Hello world!
  </body>
</html>
```
