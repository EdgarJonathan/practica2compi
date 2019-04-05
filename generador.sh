function pause(){
   read -p "$*"
}
pause 'Presione [ENTER] para generar el Lexico...'
echo -e 
echo "generando el lexico ..."
flex lexico.l 
ls -l scanner*
echo -e 
pause 'Presione [ENTER] para generar el sintactico...'
echo -e 
echo "generando el sintactico ..."
bison -t -d -v parser.yy
ls -l parser*
