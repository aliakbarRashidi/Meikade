/*
    Copyright (C) 2017 Aseman Team
    http://aseman.co

    Meikade is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Meikade is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MEIKADE_H
#define MEIKADE_H

#include <QObject>
#include <QSettings>
#include <QStringList>

class QQuickItem;
class QSettings;
class MeikadeDatabase;
class MeikadePrivate;
class Meikade : public QObject
{
    Q_PROPERTY(QString poemsFont READ poemsFont WRITE setPoemsFont NOTIFY poemsFontChanged)
    Q_PROPERTY(bool animations READ animations WRITE setAnimations NOTIFY animationsChanged)
    Q_PROPERTY(QString resourcePath READ resourcePath NOTIFY resourcePathChanged)
    Q_PROPERTY(bool nightTheme READ nightTheme WRITE setNightTheme NOTIFY nightThemeChanged)
    Q_PROPERTY(bool keepScreenOn READ keepScreenOn WRITE setKeepScreenOn NOTIFY keepScreenOnChanged)
    Q_PROPERTY(bool phrase READ phrase WRITE setPhrase NOTIFY phraseChanged)
    Q_PROPERTY(bool activePush READ activePush WRITE setActivePush NOTIFY activePushChanged)
    Q_PROPERTY(QString thumbsPath READ thumbsPath NOTIFY fakeSignal)
    Q_OBJECT

public:
    Meikade(QObject *parent = 0);
    virtual ~Meikade();

    Q_INVOKABLE bool fileExists( const QString & file );

    Q_INVOKABLE QChar convertChar( const QChar & ch );
    Q_INVOKABLE QString numberToArabicString( int number );
    Q_INVOKABLE bool endUsingNumber(const QString &str);

    Q_INVOKABLE QStringList findBackups();
    Q_INVOKABLE QString fileName( const QString & path );
    Q_INVOKABLE QString fileSuffix( const QString & path );

    Q_INVOKABLE QStringList availableFonts();
    Q_INVOKABLE qreal fontPointScale( const QString & fontName );

    Q_INVOKABLE QQuickItem *createObject(const QString &code);

    QString thumbsPath() const;

    MeikadeDatabase *database() const;

    static QString resourcePathAbs();
    static QString resourcePath();
    static Meikade *instance();

    Q_INVOKABLE qint64 mSecsSinceEpoch() const;

    Q_INVOKABLE void removeFile( const QString & path );

    Q_INVOKABLE void setProperty( QObject *obj, const QString & property, const QVariant & v );
    Q_INVOKABLE QVariant property( QObject *obj, const QString & property );

    Q_INVOKABLE void setAnimations( bool stt );
    Q_INVOKABLE bool animations() const;

    void setNightTheme( bool stt );
    bool nightTheme() const;

    void setKeepScreenOn(bool stt, bool force = false);
    bool keepScreenOn() const;

    void setPhrase(bool stt);
    bool phrase() const;

    void setActivePush(bool stt);
    bool activePush() const;

    Q_INVOKABLE QString aboutHafezOmen() const;

    void setPoemsFont( const QString & name );
    QString poemsFont() const;

    static QSettings *settings();

public Q_SLOTS:
    void start();
    void close();

    void timer( int interval, QObject *obj, const QString & member );

Q_SIGNALS:
    void closeRequest();
    void poemsFontChanged();
    void animationsChanged();
    void nightThemeChanged();
    void keepScreenOnChanged();
    void phraseChanged();
    void activePushChanged();
    void fakeSignal();

    void resourcePathChanged();

protected:
    bool eventFilter(QObject *o, QEvent *e);

private:
    MeikadePrivate *p;
};

#endif // MEIKADE_H
