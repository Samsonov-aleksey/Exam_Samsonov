#include "functions.h"
#include "database.h"

/* Функция проверки логина/пароля: на вход подаются переменные типа std::string log и pass, в которых
 * находятся данные, введенные пользователем,
если авторизация успешна, получаем сообщение: "authorization yes ", а если нет, то "authorization error " на выходе
*/
QString authorize(std::string log,std::string pass)
{
    QString  result;
    DataBase db;
    db.connectToDataBase();
    if (db.bdquery("select * from calls where number = '"+ QString::fromStdString(log) + "' AND code = '" + QString::fromStdString(pass) +"'") == "query done")
    {
        result = "authorization yes ";}
    else
        result = "authorization error ";

    return result;
}

QString bdquery(QString temp){
    QSqlQuery query;
    query.exec(temp);
    QString id, number, code, doctor_id, time_rec;
    QString array;
    while (query.next()) {
    id = query.value(0).toString();
    number = query.value(1).toString();
    //code = query.value(2).toString();
    doctor_id = query.value(3).toString();
    time_rec = query.value(4).toString();
    array.append(id);
    array.append("\t");
    array.append(number);
    array.append("\t");
    array.append(doctor_id);
    array.append("\t");
    array.append(time_rec);
    array.append("\n");
    }
    return array;
}

QString bdquery2(QString temp){
    QSqlQuery query;
    query.exec(temp);
    QString id, name, time, specialization;
    QString array2;
    while (query.next()) {
    id = query.value(0).toString();
    name = query.value(1).toString();
    time = query.value(2).toString();
    specialization = query.value(3).toString();
    array2.append(id);
    array2.append("\t");
    array2.append(name);
    array2.append("\t");
    array2.append(time);
    array2.append("\t");
    array2.append(specialization);
    array2.append("\n");
    }
    return array2;
}
