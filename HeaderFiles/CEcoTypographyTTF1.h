/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_H__

#include "IEcoTypographyTTF1.h"
#include "IEcoSystem1.h"
#include "IdEcoString1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoFileSystemManagement1.h"

typedef struct CEcoTypographyTTF1 {

    /* Таблица функций интерфейса IEcoTypographyTTF1 */
    IEcoTypographyTTF1VTbl* m_pVTblIEcoTypographyTTF1;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;
    
    /* Интерфейса для работы с интерфейсной шиной */
    IEcoInterfaceBus1* m_pIBus;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIStr;

    /* Интерфейс для работы с файлами */
    IEcoFileManager1* m_pIFileManager;
    IEcoFile1* m_pIFile;

    /* Данные экземпляра */
    char_t* m_Name;

} CEcoTypographyTTF1, *CEcoTypographyTTF1Ptr;

/* Инициализация экземпляра */
int16_t initCEcoTypographyTTF1(/*in*/ struct IEcoTypographyTTF1* me, /* in */ IEcoUnknown *pIUnkSystem);
/* Создание экземпляра */
int16_t createCEcoTypographyTTF1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1** ppIEcoTypographyTTF1);
/* Удаление */
void deleteCEcoTypographyTTF1(/* in */ IEcoTypographyTTF1* pIEcoTypographyTTF1);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_H__ */
