# saleae-docs

These documents were built using [Jekyll](https://jekyllrb.com/).

The built site can be viewed at [https://shawnhymel.github.io/saleae-docs/](https://shawnhymel.github.io/saleae-docs/).

## Directory Structure (well, the important ones)

 * **_pages/** - Your markdown files go in here
 * **_site/** - This is where the HTML files will go after building
 * **assets** - Put assets here, such as images, PDFs, etc.
 
## How to Build

Install Jekyll, as per [these instructions](https://jekyllrb.com/docs/installation/).

Open a terminal and navigate to this directory. Run Jekyll.

    jekyll build
    
This will grab files from the *_pages/* and *assets/* directories, build static HTML pages, and put them into *_site/*.

## Serve Website Locally

Open **Gemfile**. Uncomment *gem "jekyll"* and comment out *gem "github-pages"*.

Run the following command:

    jekyll serve
    
Site available at [http://localhost:4000/](http://localhost:4000/).
    
## Serve on github-pages

Open **Gemfile**. Uncomment *gem "github-pages"* and comment out *gem "jekyll"*.

In GitHub repository settings, make sure GitHub Pages is enabled and set **Source** to *master branch*.

Git add, commit, and push to repository.

Site available at https://\<YOUR GITHUB USERNAME\>.github.io/saleae-docs/