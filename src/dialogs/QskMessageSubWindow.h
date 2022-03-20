/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#ifndef QSK_MESSAGE_SUB_WINDOW_H
#define QSK_MESSAGE_SUB_WINDOW_H

#include "QskDialogSubWindow.h"

class QskGraphic;
class QskTextOptions;

class QSK_EXPORT QskMessageSubWindow : public QskDialogSubWindow
{
    Q_OBJECT

    Q_PROPERTY( QString text READ text
        WRITE setText NOTIFY textChanged )

    Q_PROPERTY( QskTextOptions textOptions READ textOptions
        WRITE setTextOptions NOTIFY textOptionsChanged )

    Q_PROPERTY( QUrl symbolSource READ symbolSource WRITE setSymbolSource )

    using Inherited = QskDialogSubWindow;

  public:
    QskMessageSubWindow( QQuickItem* parent = nullptr );
    ~QskMessageSubWindow() override;

    void setTextOptions( const QskTextOptions& );
    QskTextOptions textOptions() const;

    QString text() const;

    void setSymbolSource( const QUrl& url );
    QUrl symbolSource() const;

    void setSymbolType( int symbolType );

    void setSymbol( const QskGraphic& );
    QskGraphic symbol() const;

  public Q_SLOTS:
    void setText( const QString& );

  Q_SIGNALS:
    void textChanged( const QString& );
    void textOptionsChanged( const QskTextOptions& );

  private:
    class PrivateData;
    std::unique_ptr< PrivateData > m_data;
};

#endif
