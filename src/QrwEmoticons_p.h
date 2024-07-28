#ifndef QRWEMOTICONS_P_H
#define QRWEMOTICONS_P_H

#include "QrwEmoticons"

#include <QObject>

#include <memory>

typedef QSet<QrwEmoticons::Emoticon> EmoticonsData;

class Provider
{
public:
    virtual ~Provider() = default;

    virtual QString id() const = 0;
    virtual bool hasEmoticon(const QrwEmoticons::Emoticon &code) const = 0;
    virtual QPixmap getEmoticon(const QrwEmoticons::Emoticon &code, const QSize &size) const = 0;
};

class GoogleProvider : public Provider
{
public:
    QString id() const override;
    bool hasEmoticon(const QrwEmoticons::Emoticon &code) const override;
    QPixmap getEmoticon(const QrwEmoticons::Emoticon &code, const QSize &size) const override;

private:
    QString getEmoticonPath(const QrwEmoticons::Emoticon &code) const;
};

class TwitterProvider : public Provider
{
public:
    QString id() const override;
    bool hasEmoticon(const QrwEmoticons::Emoticon &code) const override;
    QPixmap getEmoticon(const QrwEmoticons::Emoticon &code, const QSize &size) const override;

private:
    QString getEmoticonPath(const QrwEmoticons::Emoticon &code) const;
};

class QrwEmoticonsPrivate : public QObject
{
    Q_OBJECT

    QRWEMOTICONS_DECLARE_PUBLIC(QrwEmoticons)

    friend class QrwEmoticonsTextObjectInterface;

public:
    ~QrwEmoticonsPrivate() = default;

    enum TextFormatProperty { EmoticonUnicode = QTextFormat::UserProperty, EmoticonImagePath, EmoticonQString };
    Q_ENUMS(TextFormatProperty)

    static QString GetEmoticonString(const QrwEmoticons::Emoticon &code);
    static QString GetEmoticonString(uint character);

protected Q_SLOTS:
    void onTextDocumentContentsChanged(int position, int charsRemoved, int charsAdded);

protected:
    explicit QrwEmoticonsPrivate(QrwEmoticons *, QTextDocument *);

    static const EmoticonsData EMOTICONS;
    static const int EmoticonTextFormatObjectType = QTextFormat::UserObject + 0xEEEE;

    bool isEmoticon(uint character);
    bool isEmoticon(const QrwEmoticons::Emoticon &code);

    QrwEmoticons::Emoticon getEmoticonCode(QTextCursor c, int *selectionLength);

    QString getDocumentText(bool html = false) const;
    QString getCursorText(const QTextCursor &cursor, bool html = false) const;

    void applyTextCharFormat(int pos = 0);

    void loadPlugin(const QString &id = QString());

    int getLineHeight(int posInDocument, const QTextFormat &format) const;

protected:
    std::unique_ptr<Provider> m_Provider;

    bool m_CurrentlyApplying;
    QTextDocument *m_TextDocument;
    quint8 m_MaxEmoticonCharCodeCount;
    QSize m_MinimumEmoticonSize;
};

inline uint qHash(const QrwEmoticons::Emoticon &code, uint seed)
{
    return qHash(QrwEmoticonsPrivate::GetEmoticonString(code), seed);
}

#endif  //QRWEMOTICONS_P_H
