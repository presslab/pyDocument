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
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <document.h>

Document getDoc(char *filename)
{
    Document doc;
    doc.doctype = -1;
    doc.filename = filename;
    doc.descriptor = openDoc(&doc);

    if (doc.descriptor > -1)
    {
        getDocType(&doc);
    }
    return doc;
};

int openDoc(Document *doc)
{
    int descriptor;

    descriptor = open(doc->filename, O_RDONLY);
    if (descriptor <= -1)
    {
        return descriptor;
    } else {
        return descriptor;
    }
};

int closeDoc(Document *doc)
{
    return close(doc->descriptor);
};

int getStartLineBack(Document *doc, int nline)
{
    int nbytes, currline, offset;
    char buffer;

    nbytes = 0;
    currline = 0;

    while (1)
    {
        offset = lseek(doc->descriptor, -(++nbytes), SEEK_END);
        if (read(doc->descriptor, &buffer, 1) == -1)
            break;

        if (buffer == '\n' || buffer == EOF)
        {
            if (currline++ > nline)
                return ++offset;
        }
    }
    return -1;
}

char *getDocLine(Document *doc, int offset)
{
    char *line;
    int size;
    char buffer; 

    buffer = ' ';
    size = 0;
    line = NULL;

    lseek(doc->descriptor, offset, SEEK_SET);
    line = malloc(size);    

    while (buffer != '\n' && buffer != EOF)
    {
        if (read(doc->descriptor, &buffer, 1) == 1)
        {
            line = realloc(line, ++size);
            line[size-1] = buffer;
            offset += size;
        } else {
            break;
        }
    }
    return line;
}

int getNextOffsetLine(Document *doc, int offset)
{
    char buffer; 

    buffer = ' ';

    lseek(doc->descriptor, offset, SEEK_SET);

    while (buffer != '\n' && buffer != EOF)
    {
        if (read(doc->descriptor, &buffer, 1) == 1)
            ++offset;
        else
            break;
    }

    return offset;
}

int getDocType(Document *doc)
{
    char buffer[10];
    size_t size = 4;
    size_t nread;
    int doctype = NOTKWON_DOC;

    nread = read(doc->descriptor, buffer, size);

    if (nread > 0)
    {
        // verify if the doc is a pdf file
        // standard header of pdf is:%PDF-1.4\n
        buffer[4] = '\0';
        if (strcmp("%PDF", buffer) == 0)
            doctype = PDF_DOC;
    }

    doc->doctype = doctype;
    return doctype;
};

