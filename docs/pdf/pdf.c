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
#include <string.h>
#include <pdf.h>


void initialize_doc(Document *doc)
{
    doc_pdf doc_internal;
    doc->doc_internal = &doc_internal;
}

void get_xref_offset(Document *doc)
{
    int nbytes, offset;
    doc_pdf *di = doc->doc_internal;

    nbytes = getStartLineBack(doc, 1);
    offset = atoi(getDocLine(doc, nbytes));
    di->xref_offset = offset;
}

void get_dictionary(char *array[], char strdict[])
{
    char *strcopy;
    int i = 0;
    int size = 0;
    char *buffer;

    // remove << >> EOF and \n\r if exist
    for (i=strlen(strdict); i>0; i--)
    {
        if (strdict[i] == '>')
        {
            size = (i - 3);
            break;
        }
    }

    strcopy = realloc(strcopy, sizeof(char) * size);
    memcpy(&strcopy[0], &strdict[2], size);
    buffer = strtok(strcopy, "/");

    i = 0;
    while (buffer != NULL)
    {
        array[i] = buffer;
        buffer = strtok(NULL, "/");
        ++i;
    }
    free(strcopy);
    array[i] = NULL;
}

/*
Trailer attributes

Size    integer(Required)
Total number of entries in the file’s cross-reference table, including the
original table and all updates.

Prev    integer
(Present only if the file has more than one cross-reference section) Byte
offset from the beginning of file to the location of the previous
cross-reference section. If the file has never been updated, it will not
contain the Prev key.

Root    dictionary
(Required; must be indirect reference) 

Info    dictionary
(Optional; must be indirect reference) Info dictionary for the document ID
array (Optional) An array of two strings, each of which is an ID. The first
ID is established when the file is created and the second ID is changed each
time the file is updated.

Encrypt dictionary
(Required if document is encrypted) 
*/
void get_trailer(Document *doc, int xref_offset)
{
    int offset = xref_offset;
    char *buffer;
    doc_pdf *di = doc->doc_internal;

    buffer = getDocLine(doc, offset);
    while (strncmp(buffer, "trailer", sizeof(char)*7) != 0)
    {
        offset = getNextOffsetLine(doc, offset);
        buffer = getDocLine(doc, offset);
    }

    offset = getNextOffsetLine(doc, offset);
    buffer = getDocLine(doc, offset);
    di->trailer_offset = offset;
    
    char *array[1000];
    get_dictionary(array, buffer);

    printf("%s\n", array[0]);
    printf("%s\n", array[1]);
    printf("%s\n", array[2]);
    printf("%s\n", array[3]);
    printf("%s\n", array[4]);
}



