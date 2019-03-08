# -*- coding: utf-8 -*-

from Ui_mainWindowGui import Ui_MainWindow
from mainWindowGui import *
from PyQt5.QtWidgets import QApplication

import sys
#reload(sys)
import importlib
importlib.reload(sys)

#sys.setdefaultencoding('utf-8')

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
    ui = MainWindow()
    ui.show()
    sys.exit(app.exec_())
