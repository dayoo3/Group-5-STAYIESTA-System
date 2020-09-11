QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bookingcreate.cpp \
    bookingdelete.cpp \
    bookingsummary.cpp \
    bookingview.cpp \
    homestayadd.cpp \
    homestaydelete.cpp \
    homestaydetail.cpp \
    homestayupdate.cpp \
    homestayview.cpp \
    loginpanel.cpp \
    main.cpp \
    mainmenucust.cpp \
    mainmenuhost.cpp \
    mainmenutech.cpp \
    paymentauthorization.cpp \
    paymentgateway.cpp \
    paymentsummary.cpp \
    popupbookingcreate.cpp \
    popupbookingdelete.cpp \
    popuphomestayadd.cpp \
    popuphomestaydelete.cpp \
    popuphomestayunavailable.cpp \
    popuphomestayupdate.cpp \
    popuppaymentsuccess.cpp \
    popupprofiledelete.cpp \
    popupprofileupdate.cpp \
    popupregisterpanel.cpp \
    popupreviewcreate.cpp \
    popuprewardapplied.cpp \
    popuprewardapplyfailed.cpp \
    popuprewardcreate.cpp \
    popuprewardused.cpp \
    popupticketcreate.cpp \
    profiledelete.cpp \
    profileview.cpp \
    registerpanel.cpp \
    reviewcreate.cpp \
    rewardcreate.cpp \
    rewardview.cpp \
    searchresult.cpp \
    ticketcreate.cpp \
    ticketview.cpp \
    userview.cpp

HEADERS += \
    allclasses.h \
    bookingcreate.h \
    bookingdelete.h \
    bookingsummary.h \
    bookingsummaryhorizontal.h \
    bookingview.h \
    dblogin.h \
    homestayadd.h \
    homestaydelete.h \
    homestaydetail.h \
    homestaydetailhorizontal.h \
    homestayupdate.h \
    homestayview.h \
    horizontal_proxy_model.h \
    loginpanel.h \
    mainmenucust.h \
    mainmenuhost.h \
    mainmenutech.h \
    paymentauthorization.h \
    paymentgateway.h \
    paymentsummary.h \
    paymentsummaryhorizontal.h \
    popupbookingcreate.h \
    popupbookingdelete.h \
    popuphomestayadd.h \
    popuphomestaydelete.h \
    popuphomestayunavailable.h \
    popuphomestayupdate.h \
    popuppaymentsuccess.h \
    popupprofiledelete.h \
    popupprofileupdate.h \
    popupregisterpanel.h \
    popupreviewcreate.h \
    popuprewardapplied.h \
    popuprewardapplyfailed.h \
    popuprewardcreate.h \
    popuprewardused.h \
    popupticketcreate.h \
    profiledelete.h \
    profileview.h \
    registerpanel.h \
    reviewcreate.h \
    rewardcreate.h \
    rewardview.h \
    searchresult.h \
    ticketcreate.h \
    ticketview.h \
    userview.h

FORMS += \
    bookingcreate.ui \
    bookingdelete.ui \
    bookingsummary.ui \
    bookingview.ui \
    homestayadd.ui \
    homestaydelete.ui \
    homestaydetail.ui \
    homestayupdate.ui \
    homestayview.ui \
    loginpanel.ui \
    mainmenucust.ui \
    mainmenuhost.ui \
    mainmenutech.ui \
    paymentauthorization.ui \
    paymentgateway.ui \
    paymentsummary.ui \
    popupbookingcreate.ui \
    popupbookingdelete.ui \
    popuphomestayadd.ui \
    popuphomestaydelete.ui \
    popuphomestayunavailable.ui \
    popuphomestayupdate.ui \
    popuppaymentsuccess.ui \
    popupprofiledelete.ui \
    popupprofileupdate.ui \
    popupregisterpanel.ui \
    popupreviewcreate.ui \
    popuprewardapplied.ui \
    popuprewardapplyfailed.ui \
    popuprewardcreate.ui \
    popuprewardused.ui \
    popupticketcreate.ui \
    profiledelete.ui \
    profileview.ui \
    registerpanel.ui \
    reviewcreate.ui \
    rewardcreate.ui \
    rewardview.ui \
    searchresult.ui \
    ticketcreate.ui \
    ticketview.ui \
    userview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS +=

DISTFILES += \
    error.png \
    icon16.png \
    logo.png \
    testDB.sqlite \
    tick.png \
    trash.png \
    verify.png
