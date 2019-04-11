#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QString>

#include <parser.h>  // Nuestro parser
#include <scanner.h>  // Nuestro scanner
#include <graficador.h> // Graficador

#include <QMainWindow>
#include <primerrecorrido.h>


extern int yyparse(); //
extern NodoAST *raiz; // Raiz del arbol
extern int linea; // Linea del token
extern int columna; // Columna de los tokens
extern int yylineno;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionCrear_triggered();

    bool on_actionGuardar_Archivo_Como_triggered();

    void on_actionAbrir_Archivo_triggered();

    bool on_actionGuardar_Archivo_triggered();

    void on_pushButton_clicked();

    void on_actionManual_Tecnico_triggered();

    void on_actionManual_Usuario_triggered();

private:
    Ui::MainWindow *ui;
    bool saveFile();
    bool maybeSave();
    QString curFile;

};

#endif // MAINWINDOW_H
