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
#include <document.h>

#ifndef PDF_H
#define PDF_H
#endif

typedef struct _doc_pdf {

    int trailer_size;
    int trailer_prev;
    char *trailer_root;
    char *trailer_info;
    char *trailer_id;
    char *trailer_dictionary;

    int trailer_offset;
    int xref_offset;

} doc_pdf;

void initialize_doc(Document *);

void get_xref_offset(Document *);

void get_dictionary(char *array[], char strdict[]);

void get_trailer(Document *, int);


