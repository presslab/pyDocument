/*
Copyright (c) 2009 Prima Tech Informatica Ltda.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <string.h>
#include <stdio.h>
#include <pdf.h>


int main(int argc, char *argv[])
{
    struct Document doc;
    int nbytes, xref_offset;
    char *line;



    doc = getDoc("/home/alexandre/Work/clientes/opovo/impresso/pdfs/01c 01CP_01.pdf");
    if (doc.doctype == 1) // we have a pdf file
    {

        initialize_doc(&doc);
        get_xref_offset(&doc);


        struct doc_pdf *di;
        di = doc.doc_internal;

        printf("xref offset is: %d\n", di->xref_offset);

/*
        nbytes = getStartLineBack(&doc, 0);
        printf("0 - %i: %s\n", nbytes, getDocLine(&doc, nbytes));

        nbytes = getStartLineBack(&doc, 1);
        printf("1 - %i: %s\n", nbytes, getDocLine(&doc, nbytes));

        nbytes = getStartLineBack(&doc, 2);
        printf("2 - %i: %s\n", nbytes, getDocLine(&doc, nbytes));

        nbytes = getStartLineBack(&doc, 3);
        printf("3 - %i: %s\n", nbytes, getDocLine(&doc, nbytes));
*/


    }   
    closeDoc(&doc);

    return 1;
}
