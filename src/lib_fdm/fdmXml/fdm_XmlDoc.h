/****************************************************************************//*
 * Copyright (C) 2019 Marek M. Cel
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 ******************************************************************************/
#ifndef FDM_XMLDOC_H
#define FDM_XMLDOC_H

////////////////////////////////////////////////////////////////////////////////

#include <string>

#include <libxml/tree.h>

#include <fdmXml/fdm_XmlNode.h>

////////////////////////////////////////////////////////////////////////////////

namespace fdm
{

/**
 * @brief XML Document class.
 */
class FDMEXPORT XmlDoc
{
public:

    /** Constrcutor. */
    XmlDoc( const std::string &fileName = std::string() );

    /** Destrcutor. */
    virtual ~XmlDoc();

    /** */
    inline XmlNode getRootNode()
    {
        return XmlNode( *m_root );
    }

    /** */
    inline bool isOpen() const
    {
        return m_open;
    }

    /** @return FDM_SUCCESS on success, FDM_FAILURE on failure. */
    int readFile( const std::string &fileName );

private:

    xmlDocPtr m_doc;

    bool m_open;

    XmlNode *m_root;
};

} // end of fdm namespace

////////////////////////////////////////////////////////////////////////////////

#endif // FDM_XMLDOCUMENT_H