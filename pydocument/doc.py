# coding: utf-8
# Copyright (c) 2009 Prima Tech Informatica Ltda.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
import _pydocument
from _pydocument import NOTKWON_DOC, PDF_DOC
from pdf import PdfDoc


class PyDocument(object):


    def __init__(self, filename):

        self._doc = None
        self.filename = filename

        self._doc = self._open() #
        self._parser = None
        if self._doc.doctype == PDF_DOC:
            self._parser = PdfDoc(self._doc)
        else:
            raise NotImplementedError("This type of file doesn't have an implementation yet")


    def __del__(self):
        self._close()


    def _open(self):
        self._doc = _pydocument.new(filename)


    def _close(self):
        if self._doc:
            _pydocument.close(self._doc)
            self._doc = None


    def getText(self, page=None):
        pass


    def getTextPosition(self, page):
        pass


    def getImages(self, page):
        pass






