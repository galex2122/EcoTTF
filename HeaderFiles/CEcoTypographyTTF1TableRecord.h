/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1TableRecord
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1TableRecord
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_TABLE_RECORD_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_TABLE_RECORD_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1TableRecord.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1TableRecord {

    /* Таблица функций интерфейса IEcoTypographyTTF1TableRecord */
    IEcoTypographyTTF1TableRecordVTbl* m_pVTblITableRecord;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_RECORD_DESCRIPTOR m_Descriptor;
    IEcoUnknown* m_Table;

} CEcoTypographyTTF1TableRecord, *CEcoTypographyTTF1TableRecordPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1TableRecord(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1TableRecord** ppITableRecord);
/* Удаление */
void deleteCEcoTypographyTTF1TableRecord(/* in */ IEcoTypographyTTF1TableRecord* pITableRecord);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_TABLE_RECORD_H__ */
