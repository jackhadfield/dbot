/*
 * This is part of the Bayesian Object Tracking (bot),
 * (https://github.com/bayesian-object-tracking)
 *
 * Copyright (c) 2015 Max Planck Society,
 * 				 Autonomous Motion Department,
 * 			     Institute for Intelligent Systems
 *
 * This Source Code Form is subject to the terms of the GNU General Public
 * License License (GNU GPL). A copy of the license can be found in the LICENSE
 * file distributed with this source code.
 */

/**
 * \file camera_data.hpp
 * \author Jan Issc (jan.issac@gmail.com)
 * \date December 2015
 */

#pragma once

#include <memory>
#include <string>
#include <Eigen/Dense>
#include <dbot/util/camera_data_provider.hpp>

namespace dbot
{

/**
 * \brief Represents a source of camera data such obtaining depth images,
 *        camera matrix and the current camera frame id. The source of the data
 *        depends on the implementation of the provided CameraDataProvider
 *        instance.
 */
class CameraData
{
public:
    /**
     * \brief Creates a CameraData using the specified data provider
     */
    CameraData(std::shared_ptr<CameraDataProvider>& data_provider);

    /**
     * \brief returns an obtained depth image as an Eigen matrix
     */
    Eigen::MatrixXd depth_image() const;

    /**
     * \brief Returns the frame_id name of the camera
     */
    std::string frame_id() const;

    /**
     * \brief Obtains the camera matrix
     */
    Eigen::Matrix3d camera_matrix() const;

    /**
     * \brief Returns the resolution integer downsampling factor
     */
    int downsampling_factor() const;

protected:
    /**
     * \brief Instance of the data provider which obtains the camera images.
     *        The source of the data depends on the implementation of
     *        \c CameraDataProvider
     */
    std::shared_ptr<CameraDataProvider> data_provider_;
};

}
