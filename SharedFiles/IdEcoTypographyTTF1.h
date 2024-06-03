/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoTypographyTTF1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoTypographyTTF1
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __ID_ECO_TYPOGRAPHY_TTF_1_H__
#define __ID_ECO_TYPOGRAPHY_TTF_1_H__

#include "IEcoBase1.h"
#include "IEcoTypographyTTF1.h"

/* EcoTypographyTTF1 CID = {F9CC67B4-93F6-4859-9E40-8FB600656E51} */
#ifndef __CID_EcoTypographyTTF1
static const UGUID CID_EcoTypographyTTF1 = {0x01, 0x10, 0xF9, 0xCC, 0x67, 0xB4, 0x93, 0xF6, 0x48, 0x59, 0x9E, 0x40, 0x8F, 0xB6, 0x00, 0x65, 0x6E, 0x51};
#endif /* __CID_EcoTypographyTTF1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_F9CC67B493F648599E408FB600656E51;
#endif

#endif /* __ID_ECO_TYPOGRAPHY_TTF_1_H__ */
