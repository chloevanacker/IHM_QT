/** \file playitem.h
 * \author NICOL Pauline SERVOIN Arnaud VANACKER Chloé
 * \date 21/11/2016
 */

#ifndef PLAYITEM
#define PLAYITEM

#include "header.h"

/** \struct PlayItem
 * \brief Structure qui contient les URLs de chacune des vidéos, ainsi que la manière dont on considère les lires (converties en noir et blanc ou pas)
 */
typedef struct PlayItem
{
    bool flag_convert; /**< La structure PlayItem contient un booléen flag_convert qui va être true si l'on veut convertir la vidéo en noir et blanc ou false sinon*/
    QUrl url; /**< La structure PlayItem contient l'Url de chacune des vidéos sous la forme d'une QUrl */

} PlayItem;

#endif // PLAYITEM
