/***************************************************************************
 *   This file is part of QSvn Project http://ar.oszine.de/projects/qsvn   *
 *   Copyright (c) 2004-2006 Andreas Richter <ar@oszine.de>                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License Version 2        *
 *   as published by the Free Software Foundation.                         *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                         *
 ***************************************************************************/


#ifndef FILELISTMODEL_H
#define FILELISTMODEL_H

//QSvn
#include "svnclient.h"

class FileListItem;


//Qt
#include <QtGui>

//SvnCpp
#include "svnqt/status.hpp"


class FileListModel : public QAbstractItemModel
{

public:
    enum SelectionFrom { WorkingCopy = 0x01,
                         File = 0x02 };
    enum Roles {
        FullFileNameRole = Qt::UserRole + 1
    };

    FileListModel( QObject *parent = 0 );
    /**
     * Create a FileListeModel with entries from a FileListModelSelection
     * @param parent
     * @param itemSelection The QItemSelectionModel from an already exitsing FileListModel
     * @return
     */
    FileListModel( QObject *parent, SvnClient::SvnAction svnAction );
    ~FileListModel();

    //basic model functions
    QModelIndex index( int row, int column, const QModelIndex &parent = QModelIndex( ) ) const;
    QModelIndex parent( const QModelIndex &index ) const;
    int rowCount( const QModelIndex &parent = QModelIndex( ) ) const;
    int columnCount( const QModelIndex &parent = QModelIndex( ) ) const;
    QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    QVariant data( const QModelIndex &index, int role ) const;
    void sort ( int column, Qt::SortOrder order = Qt::AscendingOrder );

    //make model editable
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData( const QModelIndex &index, const QVariant &value, int role );
    bool removeRows( int row, int count, const QModelIndex &parent = QModelIndex() );
    void removeAllRows();

    void loadFromWorkingCopySelection( QItemSelectionModel *itemSelection );
    void loadFromFileListSelection( QItemSelectionModel *itemSelection );
    void loadFromDirectory( QString directory, QString fileNamePrefix = "" );

private:
    FileListItem *rootItem;

    SvnClient::SvnAction m_svnAction;
    Qt::SortOrder sortOrder;

    void initModel();
    bool isStatusForModel( svn_wc_status_kind status );

    //sorting algorithms
    static bool itemLessThan( const QPair< FileListItem*, int > &left, const QPair< FileListItem*, int > &right );
    static bool itemGreaterThan( const QPair< FileListItem*, int > &left, const QPair< FileListItem*, int > &right );
};

#endif
