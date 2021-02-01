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

#include "PublicIPHostMaskerComponent.h"

#include "ComponentSystem/IComponentManager.h"

PublicIPHostMaskerComponent::PublicIPHostMaskerComponent() :
        m_hostMasker(nullptr) {

}

PublicIPHostMaskerComponent::~PublicIPHostMaskerComponent() {

}

auto PublicIPHostMaskerComponent::initialiseEvent() -> void {
    m_hostMasker = new Nedrysoft::PublicIPHostMasker::PublicIPHostMasker();

    Nedrysoft::ComponentSystem::addObject(m_hostMasker);
}

auto PublicIPHostMaskerComponent::finaliseEvent() -> void {
    if (m_hostMasker) {
        Nedrysoft::ComponentSystem::removeObject(m_hostMasker);

        delete m_hostMasker;
    }
}