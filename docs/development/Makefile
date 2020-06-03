MARKDOWN_F = $(wildcard *.md)
COMPILED_MKD = $(MARKDOWN_F:.md=.html)

all: $(COMPILED_MKD)

%.html: %.md
	markdown_py -f $@ $<

.PONY: clean
clean:
	rm *.html


