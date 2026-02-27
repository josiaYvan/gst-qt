/****************************************************************************
** Meta object code from reading C++ file 'playlist_view.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../playlist_view.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playlist_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN12PlaylistViewE_t {};
} // unnamed namespace

template <> constexpr inline auto PlaylistView::qt_create_metaobjectdata<qt_meta_tag_ZN12PlaylistViewE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "PlaylistView",
        "videoDoubleClicked",
        "",
        "file",
        "videoSelected",
        "playlistReordered",
        "filesDropped",
        "newFiles",
        "requestRemoveMedia",
        "row",
        "requestMoveMedia",
        "fromRow",
        "toRow"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'videoDoubleClicked'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'videoSelected'
        QtMocHelpers::SignalData<void(const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'playlistReordered'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'filesDropped'
        QtMocHelpers::SignalData<void(QStringList)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 7 },
        }}),
        // Signal 'requestRemoveMedia'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Signal 'requestMoveMedia'
        QtMocHelpers::SignalData<void(int, int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 11 }, { QMetaType::Int, 12 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<PlaylistView, qt_meta_tag_ZN12PlaylistViewE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject PlaylistView::staticMetaObject = { {
    QMetaObject::SuperData::link<QListView::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12PlaylistViewE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12PlaylistViewE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12PlaylistViewE_t>.metaTypes,
    nullptr
} };

void PlaylistView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PlaylistView *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->videoDoubleClicked((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->videoSelected((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->playlistReordered(); break;
        case 3: _t->filesDropped((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 4: _t->requestRemoveMedia((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->requestMoveMedia((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (PlaylistView::*)(const QString & )>(_a, &PlaylistView::videoDoubleClicked, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (PlaylistView::*)(const QString & )>(_a, &PlaylistView::videoSelected, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (PlaylistView::*)()>(_a, &PlaylistView::playlistReordered, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (PlaylistView::*)(QStringList )>(_a, &PlaylistView::filesDropped, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (PlaylistView::*)(int )>(_a, &PlaylistView::requestRemoveMedia, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (PlaylistView::*)(int , int )>(_a, &PlaylistView::requestMoveMedia, 5))
            return;
    }
}

const QMetaObject *PlaylistView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlaylistView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12PlaylistViewE_t>.strings))
        return static_cast<void*>(this);
    return QListView::qt_metacast(_clname);
}

int PlaylistView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PlaylistView::videoDoubleClicked(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void PlaylistView::videoSelected(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void PlaylistView::playlistReordered()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PlaylistView::filesDropped(QStringList _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void PlaylistView::requestRemoveMedia(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void PlaylistView::requestMoveMedia(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1, _t2);
}
QT_WARNING_POP
