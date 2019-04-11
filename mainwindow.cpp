#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCrear_triggered()
{

}

bool MainWindow::on_actionGuardar_Archivo_Como_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(
                this,
                "TextEditor - Save as",
                "/home/jonathan/Documentos/7S/compi/Practica2Compi/",
                "Text Files (*.li)"
                );

    if(!fileName.isEmpty()){
        curFile = fileName;
        return saveFile();

    }
       return false;
}


bool MainWindow::saveFile()
{

    QFile file(curFile);
    if(file.open(QFile::WriteOnly))
    {
        file.write(ui->textoEntrada->toPlainText().toUtf8());

        return  true;
    }else{

        QMessageBox::warning(
                    this,
                    "TextEditor",
                    tr("No se pudo escribir en el archivo  %1.\nError: %2")
                    .arg(curFile)
                    .arg(file.errorString())
                    );

        return false;
    }

}

bool MainWindow::maybeSave()
{
    if(ui->textoEntrada->document()->isModified()){

         QMessageBox::StandardButton ret =
                 QMessageBox::warning(
                    this,
                    "TextEditor",
                    tr("The Document has been Modified"
                       "Do you want to save your changes?"),
                    QMessageBox::Yes| QMessageBox::No|QMessageBox::Cancel
                    );

        if(ret == QMessageBox::Yes)
        {
           return on_actionGuardar_Archivo_Como_triggered();

        }else{
            return false;

        }

    }

    return true;
}


void MainWindow::on_actionAbrir_Archivo_triggered()
{
    if(maybeSave()){

        QString fileName = QFileDialog::getOpenFileName(
                    this,
                    "TextEditor - Open file",
                    "/home/jonathan/Documentos/7S/compi/Practica2Compi/",
                    "Text Files (*.li)"
                    );

        if(!fileName.isEmpty())
        {
            QFile file(fileName);

            if(file.open(QFile::ReadOnly)){
                ui->textoEntrada->setPlainText(file.readAll());
            }else {
                QMessageBox::warning(
                       this,
                        "TextEditor",
                        tr("Cannot read File %1.\nError: %2")
                        .arg(fileName)
                        .arg(file.errorString())
                );

            }
        }
    }
}

bool MainWindow::on_actionGuardar_Archivo_triggered()
{
    if(curFile.isEmpty())
    {
       return on_actionGuardar_Archivo_Como_triggered();
    }else {
       return saveFile();
    }
}

void MainWindow::on_pushButton_clicked()
{

    ui->textoConsola->setPlainText("");
    QString programa = ui->textoEntrada->toPlainText();

    YY_BUFFER_STATE buffer = yy_scan_string(programa.toUtf8().constData());
    /*Limpiamos los contadores
    ya que son variables globales*/
    linea = 0;
    columna = 0;
    yylineno = 0;

    if(yyparse()==0) // Si nos da un número negativo, signifca error.
    {
        /*Instanciamos un graficador y graficamos*/
        graficador *graf = new graficador(raiz);
        graf->generarImagen();
        /*Instanciamos nuestro interprete y le enviamos nuestro arbol para ejecutarse.*/
        accion * interprete = new accion();
        interprete->init(raiz);
        ui->textoConsola->setPlainText(interprete->resultado);
    }

}

void MainWindow::on_actionManual_Tecnico_triggered()
{

 system("xdg-open  /home/jonathan/Escritorio/Manuales/ManualTecnico.pdf");
}

void MainWindow::on_actionManual_Usuario_triggered()
{
     system("xdg-open   /home/jonathan/Escritorio/Manuales/ManualUsuario.pdf");
}
