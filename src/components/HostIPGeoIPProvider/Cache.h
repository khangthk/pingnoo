/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of Pingnoo (https://github.com/nedrysoft/pingnoo)
 *
 * An open-source cross-platform traceroute analyser.
 *
 * Created by Adrian Carpenter on 27/03/2020.
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

#ifndef PINGNOO_COMPONENTS_HOSTIPGEOIPPROVIDER_CACHE_H
#define PINGNOO_COMPONENTS_HOSTIPGEOIPPROVIDER_CACHE_H

#include <QJsonObject>
#include <QSqlDatabase>

namespace Nedrysoft { namespace HostIPGeoIPProvider {
    /**
     * @brief       The Cache class provides a basic cache for IP results to prevent too many requests being made.
     */
    class Cache {
        public:
            /**
             * @brief       Constructs a Cache.
             */
            Cache();

            /**
             * @brief       Destroys the Cache.
             */
            ~Cache();

            /**
             * @brief       Adds a lookup result to the cache.
             *
             * @param[in]   object the JSON formatted object to add to the cache.
             */
            auto add(QJsonObject object) -> void;

            /**
             * @brief       Check if a host has a cache entry.
             *
             * @param[in]   name the host (name or ip string) to perform the lookup on.
             * @param[out]  object the JSON object containing the host information.
             *
             * @returns     returns true if cached; otherwise false.
             */
            auto find(const QString &name, QJsonObject &object) -> bool;
    };
}}

#endif // PINGNOO_COMPONENTS_HOSTIPGEOIPPROVIDER_CACHE_H
