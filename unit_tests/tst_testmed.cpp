#include <QtTest>
#include "database.h"

class testmed : public QObject
{
    Q_OBJECT

public:
    testmed();
    ~testmed();
    DataBase * m_cntrlBD;
    
private slots:
    void initTestCase();
    void cleanupTestCase();
    void open_db();    
};

testmed::testmed()
{
    m_cntrlBD = new DataBase;
}

testmed::~testmed()
{
    delete m_cntrlBD;
}

void testmed::initTestCase()
{
}

void testmed::cleanupTestCase()
{
}

void testmed::open_db()
{
    QVERIFY(m_cntrlBD->openDataBase() == 1);
}

QTEST_APPLESS_MAIN(testmed)

#include "tst_testmed.moc"
