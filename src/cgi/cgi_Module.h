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
#ifndef CGI_MODULE_H
#define CGI_MODULE_H

////////////////////////////////////////////////////////////////////////////////

#include <osg/Group>

////////////////////////////////////////////////////////////////////////////////

namespace cgi
{

/**
 * @brief Simulation CGI module base class.
 */
class Module
{
public:

    typedef std::vector< Module* > List;

    /**
     * Constructor.
     * @param parent parent module
     */
    Module( Module *parent = 0 );

    /** Destructor. */
    virtual ~Module();

    /** Adds child to the module. */
    virtual void addChild( Module *child );

    /** Updates module and all its children. */
    virtual void update();

    /** Returns module OSG root node.  */
    inline osg::Group* getNode() { return m_root.get(); }

protected:

    osg::ref_ptr<osg::Group> m_root;    ///< OSG module root node

    List m_children;                    ///< children nodes

    Module *m_parent;                   ///< parent node

    /** Removes all children. */
    virtual void removeAllChildren();
};

} // end of cgi namespace

////////////////////////////////////////////////////////////////////////////////

#endif // CGI_MODULE_H