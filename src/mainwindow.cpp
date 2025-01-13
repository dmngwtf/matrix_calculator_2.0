#include "mainwindow.h"
#include <QCoreApplication>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QHeaderView>
#include <QMessageBox>
#include <QFont>
#include <QTableWidget>


QString value1 = "", total = "";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*-------------------------------------------------------- the first table */

    // Creating a new table
    table_widget = new QTableWidget(this);
    table_widget->setGeometry(10, 10, 250, 250);
    table_widget->setMaximumSize(250, 250);
    table_widget->setShowGrid(true);
    table_widget->setRowCount(1);
    table_widget->setColumnCount(1);


    //test
    det1Label = new QLabel(" ", this);
    det1Label->setGeometry(QRect(QPoint(820,400), QSize(500, 300)));
    QFont f1("Arial", 17, QFont::StyleNormal);
    det1Label->setFont(f1);
    det1Label->setText("Курсовая работа студентов группы БИТ231 \nБагаутдинова Эмиля и Кривошеева Тимура");

    // Setting the value of a single cell
    table_widget->setItem(0, 0, new QTableWidgetItem(" "));
    table_widget->setColumnWidth(0, 50);

    table_widget->setEditTriggers(QAbstractItemView::DoubleClicked);
    table_widget->setSelectionBehavior(QAbstractItemView::SelectRows);
    table_widget->setSelectionMode(QAbstractItemView::SingleSelection);

    /*-------------------------------------------------------- the second table */
    // Creating a new table
    table_widget2 = new QTableWidget(this);
    table_widget2->setGeometry(450, 10, 250, 250);
    table_widget2->setMaximumSize(250, 250);
    table_widget2->setShowGrid(true);
    table_widget2->setRowCount(1);
    table_widget2->setColumnCount(1);
    // Setting the value of a single cell
    table_widget2->setItem(0, 0, new QTableWidgetItem(" "));
    table_widget2->setColumnWidth(0,50);

    table_widget2->setEditTriggers(QAbstractItemView::DoubleClicked);
    table_widget2->setSelectionBehavior(QAbstractItemView::SelectRows);
    table_widget2->setSelectionMode(QAbstractItemView::SingleSelection);

    /*-------------------------------------------------------- the third table */
    // Creating a new table
    table_widget3 = new QTableWidget(this);
    table_widget3->setGeometry(850, 10, 250, 250);
    table_widget3->setMaximumSize(250, 250);
    table_widget3->setShowGrid(true);
    table_widget3->setRowCount(1);
    table_widget3->setColumnCount(1);
    // Setting the value of a single cell
    table_widget3->setItem(0, 0, new QTableWidgetItem(" "));
    table_widget3->item(0,0)->setTextAlignment(Qt::AlignCenter);
    table_widget3->setColumnWidth(0,50);


    /* -------------------------------------------------------- for labels */

    label = new QLabel(" ", this);
    label->setGeometry(QRect(QPoint(352,100), QSize(50, 50)));

    equalLabel = new QLabel("=", this);
    QFont f("Arial", 25, QFont::StyleNormal);
    equalLabel->setFont(f);
    equalLabel->setGeometry(QRect(QPoint(773,100), QSize(50, 50)));






    /* --------------------------------------------------------------------- buttons */

    /* -------------------------------------------------------- for two matrices */

    add_button = new QPushButton("+", this);
    add_button->setGeometry(QRect(QPoint(305,200), QSize(100,50)));
    connect(add_button, SIGNAL(released()), this, SLOT(add()));

    subtract_button = new QPushButton("-", this);
    subtract_button->setGeometry(QRect(QPoint(305,250), QSize(100,50)));
    connect(subtract_button, SIGNAL(released()), this, SLOT(subtract()));

    multiply_button = new QPushButton("x", this);
    multiply_button->setGeometry(QRect(QPoint(305,300), QSize(100,50)));
    connect(multiply_button, SIGNAL(released()), this, SLOT(multiply()));


    /* -------------------------------------------------------- for first matrix */

    add_row_button = new QPushButton("Добавить ряд", this);
    add_row_button->setGeometry(QRect(QPoint(30, 270), QSize(100,50)));

    connect(add_row_button, SIGNAL(released()), this, SLOT(addRow()));

    add_col_button = new QPushButton("Добавить столбец", this);
    add_col_button->setGeometry(QRect(QPoint(130, 270), QSize(130,50)));
    connect(add_col_button, SIGNAL(released()), this, SLOT(addCol()));

    delete_row_button = new QPushButton("Удалить ряд", this);
    delete_row_button->setGeometry(QRect(QPoint(30, 320), QSize(100,50)));
    connect(delete_row_button, SIGNAL(released()), this, SLOT(deleteRow()));

    delete_col_button = new QPushButton("Удалить столбец", this);
    delete_col_button->setGeometry(QRect(QPoint(130, 320), QSize(130,50)));
    connect(delete_col_button, SIGNAL(released()), this, SLOT(deleteCol()));

    determinant_button = new QPushButton("Детерминант", this);
    determinant_button->setGeometry(QRect(QPoint(30, 370), QSize(100,50)));
    connect(determinant_button, SIGNAL(released()), this, SLOT(determinant()));

    inverse_button = new QPushButton("Обратная", this);
    inverse_button->setGeometry(QRect(QPoint(130, 370), QSize(130,50)));
    connect(inverse_button, SIGNAL(released()), this, SLOT(inverse()));


    transpose_button = new QPushButton("Транспонирование", this);
    transpose_button->setGeometry(QRect(QPoint(50, 420), QSize(150,50)));
    connect(transpose_button, SIGNAL(released()), this, SLOT(transpose()));

    /* -------------------------------------------------------- for second matrix */

    add_row_button2 = new QPushButton("доб. ряд", this);
    add_row_button2->setGeometry(QRect(QPoint(480, 270), QSize(100,50)));
    connect(add_row_button2, SIGNAL(released()), this, SLOT(addRow2()));
    add_row_button2->setStyleSheet("background-color: #555555;");
    add_row_button2->setStyleSheet("color: #55555;");

    add_col_button2 = new QPushButton("доб. столбец", this);
    add_col_button2->setGeometry(QRect(QPoint(580, 270), QSize(100,50)));
    connect(add_col_button2, SIGNAL(released()), this, SLOT(addCol2()));

    delete_row_button2 = new QPushButton("уд. ряд", this);
    delete_row_button2->setGeometry(QRect(QPoint(480, 320), QSize(100,50)));
    connect(delete_row_button2, SIGNAL(released()), this, SLOT(deleteRow2()));

    delete_col_button2 = new QPushButton("уд. столбец", this);
    delete_col_button2->setGeometry(QRect(QPoint(580, 320), QSize(100,50)));
    connect(delete_col_button2, SIGNAL(released()), this, SLOT(deleteCol2()));

    determinant_button2 = new QPushButton("детерминант", this);
    determinant_button2->setGeometry(QRect(QPoint(480, 370), QSize(100,50)));
    connect(determinant_button2, SIGNAL(released()), this, SLOT(determinant2()));

    inverse_button2 = new QPushButton("обратная", this);
    inverse_button2->setGeometry(QRect(QPoint(580, 370), QSize(100,50)));
    connect(inverse_button2, SIGNAL(released()), this, SLOT(inverse2()));

    transpose_button2 = new QPushButton("Транспонирование", this);
    transpose_button2->setGeometry(QRect(QPoint(500, 420), QSize(150,50)));
    connect(transpose_button2, SIGNAL(released()), this, SLOT(transpose2()));
}


/*------------------------------------------------------------- Functions for 2 Matrices */

void MainWindow::add()
{
    // Display the plus sign
    value1 = "+";
    QFont f("Arial", 25, QFont::StyleNormal);
    label->setFont(f);
    label->setText(value1);

    // Set the second table
    if((table_widget2->columnCount() != table_widget->columnCount()) || (table_widget2->rowCount() != table_widget->rowCount()))
    {
        /*  For the second table  */
        table_widget2->setColumnCount(table_widget->columnCount());
        table_widget2->setRowCount(table_widget->rowCount());
        table_widget2->setColumnWidth(table_widget2->columnCount()-1, 50);

        // for all the items in the table
        for(int i = 0; i < table_widget2->rowCount(); i++)
        {
            for(int k = 0; k < table_widget2->columnCount(); k++)
            {
                table_widget2->setItem(i, k, new QTableWidgetItem(" "));
                table_widget2->setColumnWidth(k, 50);
            }
        }
    }


    if((table_widget3->columnCount() != table_widget->columnCount()) || (table_widget3->rowCount() != table_widget->rowCount()))
    {

        table_widget3->setColumnCount(table_widget->columnCount());
        table_widget3->setRowCount(table_widget->rowCount());

        table_widget3->setColumnWidth(table_widget3->columnCount()-1, 50);


        for(int i = 0; i < table_widget3->rowCount(); i++)
        {
            for(int k = 0; k < table_widget3->columnCount(); k++)
            {
                table_widget3->setItem(i, k, new QTableWidgetItem(" "));
                table_widget3->setColumnWidth(k, 50);
            }
        }
    }
    // получение значений из 1 матрицы
    m1.setSize(table_widget->rowCount(), table_widget->columnCount());

    // получение значений из таблицы
    for(int i = 0; i < table_widget->rowCount(); i++)
    {
        for(int k = 0; k < table_widget->columnCount(); k++)
        {
            QString s = table_widget->item(i, k)->text();
            Fraction value2 = Fraction(s.QString::toStdString());
            m1.setValue(i, k, value2);
        }
    }

    // получение значений из 2 матриы
    m2.setSize(table_widget2->rowCount(), table_widget2->columnCount());

    // для каждого элемента в таблице
    for(int i = 0; i < table_widget2->rowCount(); i++)
    {
        for(int k = 0; k < table_widget2->columnCount(); k++)
        {
            QString s = table_widget2->item(i, k)->text();
            Fraction value2 = Fraction(s.QString::toStdString());
            m2.setValue(i, k, value2);
        }
    }

    //m3.setSize(table_widget3->rowCount(), table_widget3->columnCount());
    m3.setSize(m2.getRows(),m2.getCols());
    m3 = m1+m2;

    if((m3.getRows() == table_widget3->rowCount()) && (m3.getCols() == table_widget3->columnCount()))
    {
        for(int rows = 0; rows < m3.getRows(); rows++)
        {
            for(int cols = 0; cols < m3.getCols(); cols++)
            {
                Fraction value = m3.getValue(rows, cols);
                QString b = QString::fromStdString(FractionToString(value));
                //QString b = QString::number(value);
                Fraction ans;
                ans+= m1.getValue(rows,cols);
                ans+= m2.getValue(rows,cols);
                QString c = QString::fromStdString(FractionToString(ans));
                //label_test->setText(c);
                table_widget3->item(rows, cols)->setText(c);
            }
        }
    }
}

void MainWindow::subtract()
{
    // Display the minus sign
    value1 = "-";
    QFont f("Arial", 25, QFont::StyleNormal);
    label->setFont(f);
    label->setText(value1);



    // Set the second table
    if((table_widget2->columnCount() != table_widget->columnCount()) || (table_widget2->rowCount() != table_widget->rowCount()))
    {
        /*  For the second table  */
        table_widget2->setColumnCount(table_widget->columnCount());
        table_widget2->setRowCount(table_widget->rowCount());
        table_widget2->setColumnWidth(table_widget2->columnCount()-1, 50);

        // for all the items in the table
        for(int i = 0; i < table_widget2->rowCount(); i++)
        {
            for(int k = 0; k < table_widget2->columnCount(); k++)
            {
                table_widget2->setItem(i, k, new QTableWidgetItem(" "));
                table_widget2->setColumnWidth(k, 50);
            }
        }
    }

    // For the third table
    if((table_widget3->columnCount() != table_widget->columnCount()) || (table_widget3->rowCount() != table_widget->rowCount()))
    {
        /*  For the answer table  */
        table_widget3->setColumnCount(table_widget->columnCount());
        table_widget3->setRowCount(table_widget->rowCount());

        table_widget3->setColumnWidth(table_widget3->columnCount()-1, 50);

        // for all the items in the table
        for(int i = 0; i < table_widget3->rowCount(); i++)
        {
            for(int k = 0; k < table_widget3->columnCount(); k++)
            {
                table_widget3->setItem(i, k, new QTableWidgetItem(" "));
                table_widget3->setColumnWidth(k, 50);
            }
        }
    }

    // Get the values from the first table
    m1.setSize(table_widget->rowCount(), table_widget->columnCount());

    // Get the values from the table
    for(int i = 0; i < table_widget->rowCount(); i++)
    {
        for(int k = 0; k < table_widget->columnCount(); k++)
        {
            QString s = table_widget->item(i, k)->text();
            Fraction value2 = Fraction(s.QString::toStdString());
            m1.setValue(i, k, value2);
        }
    }

    // Get the values from the second table
    m2.setSize(table_widget2->rowCount(), table_widget2->columnCount());

    // for all the items in the table
    for(int i = 0; i < table_widget2->rowCount(); i++)
    {
        for(int k = 0; k < table_widget2->columnCount(); k++)
        {
            QString s = table_widget2->item(i, k)->text();
            Fraction value2 = Fraction(s.QString::toStdString());
            m2.setValue(i, k, value2);
        }
    }

    m3.setSize(m2.getRows(), m2.getCols());
    m3 = m1 - m2;

    // As long as the display and matrix are the same size
    if((m3.getRows() == table_widget3->rowCount()) && (m3.getCols() == table_widget3->columnCount()))
    {
        for(int rows = 0; rows < m3.getRows(); rows++)
        {
            for(int cols = 0; cols < m3.getCols(); cols++)
            {
                // value = m3.getValue(rows, cols);
                //QString b = QString::fromStdString(FractionToString(value));
                Fraction ans;
                ans= m1.getValue(rows,cols);
                ans-= m2.getValue(rows,cols);
                QString с = QString::fromStdString(FractionToString(ans));
                table_widget3->item(rows, cols)->setText(с);
            }
        }
    }
}

void MainWindow::multiply()
{
    value1 = "x";
    QFont f("Arial", 25, QFont::StyleNormal);
    label->setFont(f);
    label->setText(value1);



    // The insides of the must be the same
    if((table_widget->columnCount() != table_widget2->rowCount()))
    {
        /*  For the second table  */
        table_widget2->setRowCount(table_widget->columnCount());
        table_widget2->setColumnWidth(table_widget2->columnCount()-1, 50);

        // for all the items in the table
        for(int i = 0; i < table_widget2->rowCount(); i++)
        {
            for(int k = 0; k < table_widget2->columnCount(); k++)
            {
                table_widget2->setItem(i, k, new QTableWidgetItem("0"));
                table_widget2->setColumnWidth(k, 50);
            }
        }
    }

    if((table_widget3->rowCount() != table_widget->rowCount()) || (table_widget3->columnCount() != table_widget2->columnCount()))
    {

        table_widget3->setRowCount(table_widget->rowCount());
        table_widget3->setColumnCount(table_widget2->columnCount());
        table_widget3->setColumnWidth(table_widget2->columnCount()-1, 50);


        for(int i = 0; i < table_widget3->rowCount(); i++)
        {
            for(int k = 0; k < table_widget3->columnCount(); k++)
            {
                table_widget3->setItem(i, k, new QTableWidgetItem(" "));
                table_widget3->setColumnWidth(k, 50);
            }
        }
    }


    // Get the values from the first table
    m1.setSize(table_widget->rowCount(), table_widget->columnCount());

    // Get the values from the table
    for(int i = 0; i < table_widget->rowCount(); i++)
    {
        for(int k = 0; k < table_widget->columnCount(); k++)
        {
            QString s = table_widget->item(i, k)->text();
            Fraction value2 = Fraction(s.QString::toStdString());
            m1.setValue(i, k, value2);
        }
    }

    // Get the values from the second table
    m2.setSize(table_widget2->rowCount(), table_widget2->columnCount());

    // for all the items in the table
    for(int i = 0; i < table_widget2->rowCount(); i++)
    {
        for(int k = 0; k < table_widget2->columnCount(); k++)
        {
            QString s = table_widget2->item(i, k)->text();
            Fraction value2 = Fraction(s.QString::toStdString());
            m2.setValue(i, k, value2);
        }
    }


    m3.setSize(m1.getRows(), m2.getCols());
    //m4.setSize(m1.getCols(), m2.getRows());
    Matrix m5 = m1*m2;
    //m5.setSize(m1.getRows(), m2.getCols());

    // As long as the display and matrix are the same size
    for(int rows = 0; rows < m5.getRows(); rows++)
    {
        for(int cols = 0; cols < m5.getCols(); cols++)
        {
            Fraction value = m5.getValue(rows, cols);
            QString b = QString::fromStdString(FractionToString(value));
            table_widget3->item(rows, cols)->setText(b);
        }
    }
}

void MainWindow::addRow()
{
    table_widget->setRowCount(table_widget->rowCount()+1);

    int row = table_widget->rowCount();
    // Initialize new cells
    for(int i = 0; i < table_widget->columnCount(); i++)
    {table_widget->setItem((row-1), i, new QTableWidgetItem(" "));}
    m1.setSize(table_widget->rowCount(), table_widget->columnCount());
}

void MainWindow::addCol()
{
    table_widget->setColumnCount(table_widget->columnCount()+1);

    int col = table_widget->columnCount();
    // Initialize new cells
    for(int i = 0; i < table_widget->rowCount(); i++)
    {table_widget->setItem(i, (col-1), new QTableWidgetItem(" "));}

    table_widget->setColumnWidth((col-1), 50);
    m1.setSize(table_widget->rowCount(), table_widget->columnCount());

}

void MainWindow::deleteRow()
{
    table_widget->removeRow(table_widget->rowCount()-1);
    m1.setSize(table_widget->rowCount(), table_widget->columnCount());
}

void MainWindow::deleteCol()
{
    table_widget->removeColumn(table_widget->columnCount()-1);
    m1.setSize(table_widget->rowCount(), table_widget->columnCount());
}

void MainWindow::determinant()
{
    if(table_widget->rowCount() == table_widget->columnCount())
    {
        if(table_widget->rowCount() > 1)
        {
            // Get the values from the first table
            m1.setSize(table_widget->rowCount(), table_widget->columnCount());

            // Get the values from the table
            for(int i = 0; i < table_widget->rowCount(); i++)
            {
                for(int k = 0; k < table_widget->columnCount(); k++)
                {
                    QString s = table_widget->item(i, k)->text();
                    float value = s.toFloat();
                    m1.setValue(i, k, value);
                }
            }

            Fraction ans = m1.getDeterminant();
            QString b = QString::fromStdString("Детерминант = ") + QString::fromStdString(FractionToString(ans));
            det1Label->setText(b);
            det1Label->setAlignment(Qt::AlignCenter);
        }
    }

    else
    {


        QMessageBox abox(this);
        abox.setText("\nНе квадратная матрица!\nВведите квадратную матрицу.");
        abox.setIconPixmap(QPixmap(":/new/prefix1/Снимок экрана 2024-05-23 в 12.25.04.png"));
        abox.setParent(this);
        abox.exec();
    }
}

void MainWindow::inverse()
{
    if(table_widget->columnCount() == table_widget->rowCount())
    {
        m1.setSize(table_widget->rowCount(), table_widget->columnCount());

        // for all the items in the table
        for(int i = 0; i < table_widget->rowCount(); i++)
        {
            for(int k = 0; k < table_widget->columnCount(); k++)
            {
                QString s = table_widget->item(i, k)->text();
                float value = s.toFloat();
                m1.setValue(i, k, value);
            }
        }

        Matrix temp(table_widget->rowCount(), table_widget->columnCount());
        if(!(m1.getDeterminant()== Fraction(0)))
        {
            temp = m1.inverse();

            // As long as the display and matrix are the same size
            if((temp.getRows() == table_widget->rowCount()) && (temp.getCols() == table_widget->columnCount()))
            {
                for(int rows = 0; rows < temp.getRows(); rows++)
                {
                    for(int cols = 0; cols < temp.getCols(); cols++)
                    {

                        Fraction value = temp.getValue(rows, cols);
                        QString b = QString::fromStdString(FractionToString(value));
                        table_widget->item(rows, cols)->setText(b);
                    }
                }
            }
        }
        else
        {

            QMessageBox::critical(this, "Нельзя получить обратную матрицу.", "Нельзя получить обратную матрицу.");
        }
    }
    else
    {

        QMessageBox::critical(this, "Не квадратная матрица.", "Не квадратная матрица.");
    }
}

//2-я матрица

void MainWindow::addRow2()
{
    table_widget2->setRowCount(table_widget2->rowCount()+1);

    int row = table_widget2->rowCount();

    // Initialize new cells
    for(int i = 0; i < table_widget2->columnCount(); i++)
    {table_widget2->setItem((row-1), i, new QTableWidgetItem(" "));}

    m2.setSize(table_widget2->rowCount(), table_widget2->columnCount());
}

void MainWindow::addCol2()
{
    table_widget2->setColumnCount(table_widget2->columnCount()+1);

    int col = table_widget2->columnCount();

    // Initialize new cells
    for(int i = 0; i < table_widget2->rowCount(); i++)
    {table_widget2->setItem(i, (col-1), new QTableWidgetItem(" "));}

    table_widget2->setColumnWidth((col-1), 50);

    m2.setSize(table_widget2->rowCount(), table_widget2->columnCount());
}

void MainWindow::deleteRow2()
{
    table_widget2->removeRow(table_widget2->rowCount()-1);
    m2.setSize(table_widget2->rowCount(), table_widget2->columnCount());
}

void MainWindow::deleteCol2()
{
    table_widget2->removeColumn(table_widget2->columnCount()-1);
    m2.setSize(table_widget2->rowCount(), table_widget2->columnCount());
}

void MainWindow::determinant2()
{
    if(table_widget2->rowCount() == table_widget2->columnCount())
    {
        if(table_widget2->rowCount() > 1)
        {
            // Get the values from the first table
            m2.setSize(table_widget2->rowCount(), table_widget2->columnCount());

            // Get the values from the table
            for(int i = 0; i < table_widget2->rowCount(); i++)
            {
                for(int k = 0; k < table_widget2->columnCount(); k++)
                {
                    QString s = table_widget2->item(i, k)->text();
                    float value = s.toFloat();
                    m2.setValue(i, k, value);
                }
            }

            Fraction ans = m2.getDeterminant();
            QString b = QString::fromStdString("Детерминант = ") + QString::fromStdString(FractionToString(ans));
            det2Label->setText(b);
            det2Label->setAlignment(Qt::AlignCenter);
        }
    }

    else
    {
        QMessageBox::critical(this, "Not a Square Matrix", "Not a square matrix.");
    }
}

void MainWindow::inverse2()
{
    if(table_widget2->columnCount() == table_widget2->rowCount())
    {
        m2.setSize(table_widget2->rowCount(), table_widget2->columnCount());

        // for all the items in the table
        for(int i = 0; i < table_widget2->rowCount(); i++)
        {
            for(int k = 0; k < table_widget2->columnCount(); k++)
            {
                QString s = table_widget2->item(i, k)->text();
                float value = s.toFloat();
                m2.setValue(i, k, value);
            }
        }

        Matrix temp(table_widget2->rowCount(), table_widget2->columnCount());
        if(!(m2.getDeterminant()== 0))
        {
            temp = m2.inverse();

            // As long as the display and matrix are the same size
            if((temp.getRows() == table_widget2->rowCount()) && (temp.getCols() == table_widget2->columnCount()))
            {
                for(int rows = 0; rows < temp.getRows(); rows++)
                {
                    for(int cols = 0; cols < temp.getCols(); cols++)
                    {

                        Fraction value = temp.getValue(rows, cols);
                        QString b = QString::fromStdString(FractionToString(value));
                        table_widget2->item(rows, cols)->setText(b);
                    }
                }
            }
        }
        else
        {
            // print error: non-invertible matrix
            QMessageBox::critical(this, "Нельзя получить обратную матрицу.", "Нельзя получить обратную матрицу.");
        }
    }
    else
    {
        // print error: not a square matrix
        QMessageBox::critical(this, "Не квадратная матрица.", "Не квадратная матрица.");
    }
}
void MainWindow::transpose()
{
    if(table_widget->columnCount() == table_widget->rowCount())
    {
        m1.setSize(table_widget->rowCount(), table_widget->columnCount());

        // for all the items in the table
        for(int i = 0; i < table_widget->rowCount(); i++)
        {
            for(int k = 0; k < table_widget->columnCount(); k++)
            {
                QString s = table_widget->item(i, k)->text();
                float value = s.toFloat();
                m1.setValue(i, k, value);
            }
        }

        Matrix temp(table_widget->rowCount(), table_widget->columnCount());
        temp = m1.transpose();

        // As long as the display and matrix are the same size
        if((temp.getRows() == table_widget->rowCount()) && (temp.getCols() == table_widget->columnCount()))
        {
            for(int rows = 0; rows < temp.getRows(); rows++)
            {
                for(int cols = 0; cols < temp.getCols(); cols++)
                {
                    Fraction value = temp.getValue(rows, cols);
                    QString b = QString::fromStdString(FractionToString(value));
                    table_widget->item(rows, cols)->setText(b);
                }
            }
        }
    }

    else
    {
        // print error: not a square matrix
        QMessageBox::critical(this, "Не квадратная матрица", "Не квадратная матрица.");
    }
}

void MainWindow::transpose2()
{
    if(table_widget2->columnCount() == table_widget2->rowCount())
    {
        m2.setSize(table_widget2->rowCount(), table_widget2->columnCount());

        // for all the items in the table
        for(int i = 0; i < table_widget2->rowCount(); i++)
        {
            for(int k = 0; k < table_widget2->columnCount(); k++)
            {
                QString s = table_widget2->item(i, k)->text();
                float value = s.toFloat();
                m2.setValue(i, k, value);
            }
        }

        m3.setSize(table_widget2->rowCount(), table_widget2->columnCount());
        m3 = m2.transpose();

        // As long as the display and matrix are the same size
        if((m3.getRows() == table_widget2->rowCount()) && (m3.getCols() == table_widget2->columnCount()))
        {
            for(int rows = 0; rows < m3.getRows(); rows++)
            {
                for(int cols = 0; cols < m3.getCols(); cols++)
                {
                    Fraction value = m3.getValue(rows, cols);
                    QString b = QString::fromStdString(FractionToString(value));
                    table_widget2->item(rows, cols)->setText(b);
                }
            }
        }
    }

    else
    {
        // print error: not a square matrix
        QMessageBox::critical(this, "Не квадратная матрица", "Не квадратная матрица.");
    }
}

/*------------------------------------------------------------- Functions for Second Matrix */

MainWindow::~MainWindow()
{
}

