#ifndef LITEBENCODE_GLOBAL_H
#define LITEBENCODE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LITEBENCODE_LIBRARY)
#  define LITEBENCODE_EXPORT Q_DECL_EXPORT
#else
#  define LITEBENCODE_EXPORT Q_DECL_IMPORT
#endif

#endif // LITEBENCODE_GLOBAL_H
