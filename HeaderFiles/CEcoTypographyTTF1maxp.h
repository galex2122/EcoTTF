/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1maxp
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1maxp
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_MAXP_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_MAXP_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1maxp.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1maxp {

    /* Таблица функций интерфейса IEcoTypographyTTF1maxp */
    IEcoTypographyTTF1maxpVTbl* m_pVTblImaxp;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_MAXP_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1maxp, *CEcoTypographyTTF1maxpPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1maxp(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1maxp** ppImaxp);
/* Удаление */
void deleteCEcoTypographyTTF1maxp(/* in */ IEcoTypographyTTF1maxp* pImaxp);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_MAXP_H__ */
