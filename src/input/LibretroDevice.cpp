/*
 *      Copyright (C) 2015-2016 Team Kodi
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this Program; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "LibretroDevice.h"
#include "LibretroDeviceInput.h"
#include "ButtonMapper.h"
#include "libretro/libretro.h"

using namespace LIBRETRO;

CLibretroDevice::CLibretroDevice(const game_controller* controller)
  : m_type(RETRO_DEVICE_NONE),
    m_input(new CLibretroDeviceInput(controller))
{
  if (controller && controller->controller_id)
  {
    m_controllerId = controller->controller_id;
    m_type = CButtonMapper::Get().GetLibretroType(m_controllerId);
  }
}
