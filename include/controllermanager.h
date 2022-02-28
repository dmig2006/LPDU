#ifndef CONTROLLER_MANAGER
#define CONTROLLER_MANAGER

/*****************************************************************************/
/*** controller                                                            ***/
/*****************************************************************************/

#include <QThread>

#define VOLTAGE_BU_MIN    10
#define VOLTAGE_BU_MAX    15
#define VOLTAGE_PP_MIN 15
#define VOLTAGE_PP_MAX 24

#define COLOR_FON_INVERSIA                      "background-color:#000000"
#define COLOR_FON_NORMA                         "background-color:#D4D4D4"

#define COLOR_LINE_INVERSIA                     "background-color:#FFFFFF"
#define COLOR_LINE_NORMA                        "background-color:#D4D4D4"

#define COLOR_LOG_NORMA                         "background-color:#FFFFFF; color:#610404;"
#define COLOR_LOG_INVERSIA                      "background-color:#989197; color:#ECD2D2; border-radius:6px"

#define COLOR_BUTTON_NORMA_ACTIVATE             "background-color:#D4D4D4; color:#610404;"
#define COLOR_BUTTON_NORMA_NO_ACTIVATE          "default"
#define COLOR_BUTTON_INVERSIA_ACTIVATE          "background-color:#989197; color:#ECD2D2; border-radius:6px"
#define COLOR_BUTTON_INVERSIA_NO_ACTIVATE       "background-color:#000000; color:#F68080; border-radius:6px"

#define COLOR_LABEL_NORMA                       "color:#000000"
#define COLOR_LABEL_INVERSIA                    "color:#FFFFFF"
#define COLOR_LABEL_NORMA_DATA                  "color:#610404"
#define COLOR_LABEL_INVERSIA_DATA               "color:#F68080"

#define COLOR_BUTTON_NORMA_EXPOSITION                 "background-color:#D4D4D4; color:#D4D4D4;"

class ControllerManager : public QThread
{
    Q_OBJECT

public:
    ControllerManager();
    ~ControllerManager();

public slots:
    void setPosX_Y(int pPosX, int pPosY);

protected:

private:
    int mPosX, mPosY;

private slots:

signals:
    void newPosX_Y(int pPosX, int pPosY);

};

#endif // CONTROLLER_MANAGER
