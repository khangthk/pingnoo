/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of Pingnoo (https://github.com/nedrysoft/pingnoo)
 *
 * An open-source cross-platform traceroute analyser.
 *
 * Created by Adrian Carpenter on 10/12/2020.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PINGNOO_COMPONENTS_CORE_IRIBBONPAGE_H
#define PINGNOO_COMPONENTS_CORE_IRIBBONPAGE_H

#include "CoreSpec.h"
#include "IRibbonBarManager.h"
#include "IRibbonGroup.h"

#include <IInterface>
#include <QWidget>

namespace Nedrysoft { namespace Core {
    /**
     * @brief       The IRibbonPage interface describes a ribbon bar page.
     *
     * @details     The IRibbonPage is a container for groups.  Pages are added to the ribbon bar and each page
     *              appears as a separate tab in the ribbon bar.
     *
     * @class       Nedrysoft::Core::IRibbonPage IRibbonPage.h <IRibbonPage>
     */
    class NEDRYSOFT_CORE_DLLSPEC IRibbonPage :
        public Nedrysoft::ComponentSystem::IInterface {
            private:
                Q_OBJECT

            public:
                /**
                 * @brief       Adds a group to the page.
                 *
                 * @param[in]   title the title of the group.
                 * @param[in]   id the identifier of the group.
                 * @param[in]   widget the widget to be used in the group.
                 *
                 * @returns     the IRibbonGroup instance of the group.
                 */
                virtual auto addGroup(
                        QString title,
                        QString id,
                        QWidget *widget ) -> Nedrysoft::Core::IRibbonGroup * = 0;

            // Classes with virtual functions should not have a public non-virtual destructor:
            virtual ~IRibbonPage() = default;
    };
}}

Q_DECLARE_INTERFACE(Nedrysoft::Core::IRibbonPage, "com.nedrysoft.core.IRibbonPage/1.0.0")

#endif // PINGNOO_COMPONENTS_CORE_IRIBBONPAGE_H
