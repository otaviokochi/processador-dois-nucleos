# Makefile
all: pdflatex
TEX	:= pdflatex
DOC := processador
OPTPDF	:= yags

pdflatex:
	@$(TEX) $(DOC).tex
	@echo 'PDF => Criado'

clean:
	@rm -rf $(DOC).log $(OPTPDF).pdf $(DOC).aux
	echo -e 'Clean executado!\n'