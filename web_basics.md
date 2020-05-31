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
Note that each tag that is opened MUST be closed.  This is either achieved by a closing tag (body tag above) or by a self-closing tag, which is one without text in it (such as the link tag above).  Text in tags is never shown.

HTML has two main parts: the head and the body.
- The head is the part used to specify important components of the site that aren't shown on the actual webpage.  Title and Link are both common tags put here.  More on what they do below.
- The body is what is actually displayed on your webpage.  This is where the majority if your site should go.

You can always see what the current page you are working on looks like by hitting 'Inspect Element' on your browser or downloading the page.  An inspect element page commonly looks like:
![Inspect Element](resources/inspect.PNG)
You can clearly see the start of the html tag, head tag (which is minimized), and the start of the body.

Tags in HTML often take attributes.  Attributes are used to give more information about the tag such as an image source, specific styling to use, or an action to do when clicked.  Attributes are specified as follows:
```html
<div class="test">
  This div has an attribute 'class' with the value 'test'.
</div>
```
The most common attributes are classes and ids but other tags have their own specific attributes to add additional functionality, such as a link redirection location or alternate text for an image.  Classes and IDs will be explained more in the CSS section, but know they are separeted by spaces in HTML.

## HTML Tags
HTML has tons of included tags that do a myriad of different things.  Here are some more useful ones:
- ```<title></title>```: used to specify the title of the page, more commonly known as the name of the tab.  That is found in your web browser to preview what the tab is about and is generally on the top of your screen.  Short, informative titles are often best.  Always placed in the header.
- ```<link/>```: used to link another file (normally CSS or JS) into your document and add its attributes.  Always placed in the header.
- ```<div></div>```: used to specify a block on your site.  Information is commonly put in a div in order to apply CSS to it through classes or ids.  Divs apply no additional formatting.
- ```<p></p>```: short for paragraph, this tag is used for a paragraph of text.  It generally applies rudimentary formatting such as adding a margin below said paragraph to more clearly define it and text wrapping if not default.  Commonly put inside a div.
- ```<span></span>```: used to apply custom formatting to a specific range of text, usually in a paragraph.  Often used to change a specific word or phrase when a certain action is performed.
- ```<img/>```: defines an image to be placed in the document.  Formatting by default is the full pixel size of the image so CSS is usually necessary to fix this.  The image source is specified with the ```src``` modifier and, if the image cannot load, it shows text specified in the ```alt``` modifier.  Self-closing tag.
- ```<br/>```: makes a line break in the page.  Same as hitting enter.  Self-closing tag.
- ```<a></a>```: makes a link.  Specify link destination with ```hfef``` modifier.
-```<ol></ol> and <ul></ul>```: defines a ordered and unordered list, respectively.  Ordered lists are numbered while unordered lists use bullet points.
-```<li></li>```: defines a list item.  Work when put inside an ordered or unordered list and specify a single number/bullet point each.
-```<form></form>```: creates a new form.  Form has its own special tags that go inside to create forms to submit information, such as ```<input>``` for fields, ```<label>``` for normal text, and ```<button>``` for submitting.  More info on forms can be found [here](https://www.w3schools.com/html/html_forms.asp).
-```<col></col> and <row></row>```: used to make tables in HTML.  More commonly used with bootstrap.

## CSS Basics
CSS (Cascading Style Sheet) is used to add styling and design to a HTML document.  CSS works by using selectors and applying certain modifiers to those selectors.  A basic CSS file looks like:
```css
body {
  color: white;
  background-color: blue;
}
```
And must be imported to the HTML file you want it to apply to in the header with a ```link``` tag:
```html
<link rel="stylesheet" type="text/css" href="mystyle.css">
```
CSS has a few different types of selectors:
- Tags: Tags work just like they sound like and apply to what they describe.  For example, a ```body``` selector applies to the whole body section of the HTML document.  Important to note that tags like ```li``` will apply to EVERY list item in the whole page, not just a specific group.
- Classes: Classes are used to select a certain group of items.  Note that the key word is group as this is designed to work for multiple items on a single page.  They are specified with a dot before the class name and a ```class``` parameter in the html tag. For example, the class ```.test``` would be applied in HTML and CSS (respectively) like:
```html
<p class="test">text</p>
```
```css
.test {
  color: black;
}
```
- Ids: Work the same as classes but are designed to be unique for a specific tag and cannot be duplicated elsewhere in the document.  Used often as an identifier for JS.  Follows an indentical format as classes except go in the ```id``` parameter and are specific in CSS with a hashtag instead of a dot (ex. ```#test {}```).
- Active modifiers: Used to change an item when a certain action occurs.  The most common are active and hover which modify a clicked object and an object with a mouse on it, respectively.  They are specified with another selector and a colon.  For instance, CSS for links generally bold when the mouse is over then then change color when clicked.  Code for this looks like:
```css
a {
  color: blue;
  text-decoration: underline;
}
a:hover {
  font-weight: bold;
}
a:active {
  color: purple;
}
```
Note that CSS can also be applied directly in HTML documents two ways:
- CSS tag in the header.  Works exactly as it sounds.  Example:
```html
<style>
  body {color: red;}
</style>
```
- Inline.  This applys CSS directly to an tag in the tag declaration.  Generally used to hide objects with Jquery.  Example:
```<p style="color: white;">text</p>```

## Useful CSS modifiers
Coming soon!
