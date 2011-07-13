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
#include <document.h>

struct Document getDoc(char *filename)
{
    struct Document doc;
    doc.doctype = -1;
    doc.filename = filename;
    doc.descriptor = openDoc(&doc);

    if (doc.descriptor > -1)
    {
        getDocType(&doc);
    }
    return doc;
};

int openDoc(struct Document *doc)
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

int closeDoc(struct Document *doc)
{
    return close(doc->descriptor);
};

int getDocType(struct Document *doc)
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
        header[4] = '\0';
        if (strcmp("%PDF", header) == 0)
            doctype = PDF_DOC;
    }

    doc->doctype = doctype;
    return doctype;
};

