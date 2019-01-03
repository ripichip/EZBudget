/*
 * The Account class will set the user's inputted data into the appropiate members,
 * keep track of their spendings, and update the diagrams through
 * the use of slots and signals.
 *
 * Author: Jose Quirarte
 * Date: 2/24/18
 *
 * Edited by Alex Shershnov on 5/2/2018
 * */


#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QStringList>
#include <QVector>
#include <QObject> //allows usage of signals and slots
#include <QString>
#include "category.h"
#include "tablewidget.h"
#include "transaction.h"

class mainDashboard;

class Account : public QObject
{
    Q_OBJECT

private:
    int monthlyIncome;                     //monthly income
    int monthlyBudget;                     //stores monthly budget
    int monthlySavings;                    //stores monthly savings

    QVector<Transaction> spendings;
    QVector<Transaction> income;


    static bool failure;
    static bool success;
    mainDashboard *mainDash;
public:

    //Refactored functions
    Account();

    void getTransaction(int index, QString &category, QString &tName, QString &tDate, QString &type, int &amount)const;

    void getCategoryOfTransaction(int index, QString &category, QString &type)const;

    int calculateBudgetLeft(QString &type) const;


    int getTotalFromType(QString &type)const;
    int getTotalFromOneCategory(QString &category, QString &type)const;
    int getTotalFromTransaction(int index, QString &type)const;
    int getTotaNumberOfTransactions(QString &type)const;
    bool verifyNumber(int input);          //will make sure inputs are not negative
    int getBudget()const;
    int getIncome()const;
    int getSavings()const;
    bool isSpendingsEmpty() const;
    bool isIncomeEmpty() const;
    void invokeUi();
    mainDashboard* getDash(); //this is the only way to send the type when editing a transaction

    QStringList getSpendingCategories();
    QList<Transaction> getSpendingTransactions(const QString &category);


    Transaction getAllTransacs();

public slots:
    //setters
    bool setBudget(int b);
    void editTransactions(QString category, QString tName, QString tDate, QString &type, int amount, int index);
    void addTransactions(QString category, QString tName, QString tDate, QString &type, int amount);
    void removeTransactions(int index, QString &type);


signals:
    //the following function will send out a signal to inform diagrams to update themselves
    void accountModified();
};

#endif // ACCOUNT_H
