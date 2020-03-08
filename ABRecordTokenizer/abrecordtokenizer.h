#ifndef ABRECORDTOKENIZER_H
#define ABRECORDTOKENIZER_H

#include "ABRecordTokenizer_global.h"
#include <qfile.h>
#include <QObject>

#include "litebencode.h"
#include "signaturerecord.h"

class ABRECORDTOKENIZER_EXPORT ABRecordTokenizer: public QObject {
Q_OBJECT
    QFile *currentFile;
    LiteBencode *liteBencode;
    BListWritable *writable;
    bool reading;
    bool writing;
    int prepareCount;
    int currentCount;

public:
    explicit ABRecordTokenizer(QObject *parent = nullptr);

    ~ABRecordTokenizer();
    // ���������� ���� ���� ������
    void setBaseFile(const QString &filename);

    // ����������� ��� ������
    bool prepareForWrite(int count);

    // ��� ������� ������, ������������ � ����� ������ ����������
    bool isReading();

    // ������� ����� ������, ������ ����������
    bool isWriting();

    // ������ ������ �������, ����� ����� ����� �������.
    int readAll();

    // �������� ��������� ������, ���������� ����� ������
    int writeRecord(SignatureRecord &record);

    // ��������� �������� ����
    void close();
signals:
    void nextRecord(SignatureRecord *record, int number);
};

#endif // ABRECORDTOKENIZER_H
