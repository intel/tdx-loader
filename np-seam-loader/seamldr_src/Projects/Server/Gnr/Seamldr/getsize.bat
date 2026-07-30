  FOR /F "usebackq" %%A IN ('pseamldr.so') DO set pseamldrsize=%%~zA
  echo PSEAMLDR_SIZE EQU %pseamldrsize% > PSeamldrSize.equ