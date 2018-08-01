# goqdebug

Small go module for qt bindings to redirect qt logs (qDebug, QWarning, qInfo) to go logging system.

## Use

Just add files to your project. Can remove rcc, but be sure you have own moc or rcc to bypass qt compiler options to cpp. Also just remove main().
