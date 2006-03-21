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
#ifndef SHOWLOGREVISIONSMODEL_H
#define SHOWLOGREVISIONSMODEL_H

//SvnQt
#include "svnqt/client.hpp"

//Qt
class QAbstractTableModel;
class QModelIndex;
class QVariant;


/**
    @author Andreas Richter <ar@oszine.de>
*/
class ShowLogRevisionsModel : public QAbstractTableModel
{
public:
    ShowLogRevisionsModel( QObject * parent = 0, const svn::LogEntries *logEntries = 0 );
    ~ShowLogRevisionsModel();

    int rowCount( const QModelIndex &parent = QModelIndex( ) ) const;
    int columnCount( const QModelIndex &parent = QModelIndex( ) ) const;
    QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    QVariant data( const QModelIndex &index, int role ) const;
private:
    const svn::LogEntries *m_logEntries;
};

#endif