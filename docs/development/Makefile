markdown_f = $(wildcard *.md)
compiled_mkd = $(markdown_f:.md=.html)

all: $(compiled_mkd)

%.html: %.md
	markdown_py -f $@ $<

.PONY: clean
clean:
	rm *.html


