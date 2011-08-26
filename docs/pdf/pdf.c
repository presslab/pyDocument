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
#include <stdio.h>
#include <stdlib.h>
#include <pdf.h>


void initialize_doc(struct Document *doc)
{
    struct doc_pdf doc_internal;
    doc->doc_internal = &doc_internal;
}

void get_xref_offset(struct Document *doc)
{
    int nbytes;
    struct doc_pdf *di;

    nbytes = getStartLineBack(doc, 1);
    //todo: error
    di = doc->doc_internal;
    di->xref_offset = atoi(getDocLine(doc, nbytes));
}

void get_trailer(struct Document *doc, int xref_offset)
{


}



