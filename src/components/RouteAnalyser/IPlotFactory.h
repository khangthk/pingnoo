/*
 * Copyright (C) 2021 Adrian Carpenter
 *
 * This file is part of Pingnoo (https://github.com/nedrysoft/pingnoo)
 *
 * An open-source cross-platform traceroute analyser.
 *
 * Created by Adrian Carpenter on 14/03/2021.
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

#ifndef NEDRYSOFT_ROUTEANALYSER_IPLOTFACTORY_H
#define NEDRYSOFT_ROUTEANALYSER_IPLOTFACTORY_H

#include "RouteAnalyserSpec.h"

#include <IInterface>
#include <QMargins>

namespace Nedrysoft { namespace RouteAnalyser {
    class IPlot;

    /**
     * @brief       The IPlotFactory interface is used to instantiate extra plots which are displayed to the user.
     *
     * @class       Nedrysoft::RouteAnalyser::IPlotFactory IPlotFactory.h <IPlotFactory>
     */
    class NEDRYSOFT_ROUTEANALYSER_DLLSPEC IPlotFactory :
            public Nedrysoft::ComponentSystem::IInterface {

        private:
            Q_OBJECT

            Q_INTERFACES(Nedrysoft::ComponentSystem::IInterface)

        public:
            /**
             * @brief       Create a plot.
             *
             * @returns     the plot.
             */
            virtual auto createPlot(const QMargins &margins) -> Nedrysoft::RouteAnalyser::IPlot * = 0;

            // Classes with virtual functions should not have a public non-virtual destructor:
            virtual ~IPlotFactory() = default;
    };
}}

Q_DECLARE_INTERFACE(Nedrysoft::RouteAnalyser::IPlotFactory, "com.nedrysoft.routeanalyser.IPlotFactory/1.0.0")

#endif //NEDRYSOFT_ROUTEANALYSER_IPLOTFACTORY_H
