/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1glyf
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1glyf
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_GLYF_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_GLYF_H__

#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1glyf.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1glyf {

    /* Таблица функций интерфейса IEcoTypographyTTF1glyf */
    IEcoTypographyTTF1glyfVTbl* m_pVTblIglyf;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

	IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    IEcoList1* m_Descriptors;
	IEcoList1* m_SimpleContents;
	IEcoList1* m_CompositeContents;
    IEcoList1* m_TableDirectory;
	IEcoList1* m_ComponentsAddresses;

} CEcoTypographyTTF1glyf, *CEcoTypographyTTF1glyfPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1glyf(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1glyf** ppIglyf);
/* Удаление */
void deleteCEcoTypographyTTF1glyf(/* in */ IEcoTypographyTTF1glyf* pIglyf);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_GLYF_H__ */
