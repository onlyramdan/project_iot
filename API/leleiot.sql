-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Apr 04, 2023 at 10:58 AM
-- Server version: 10.4.27-MariaDB
-- PHP Version: 8.1.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `leleiot`
--

-- --------------------------------------------------------

--
-- Table structure for table `monitoring`
--

CREATE TABLE `monitoring` (
  `id_kondisi` int(100) NOT NULL,
  `suhu` float NOT NULL,
  `ph` float NOT NULL,
  `pakan` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `waktukasihpakan`
--

CREATE TABLE `waktukasihpakan` (
  `id_waktuMakan` int(11) NOT NULL,
  `jam` int(10) NOT NULL,
  `menit` int(10) NOT NULL,
  `detik` int(100) NOT NULL,
  `lamaPakan` int(100) NOT NULL,
  `kecepatan` int(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `waktukasihpakan`
--

INSERT INTO `waktukasihpakan` (`id_waktuMakan`, `jam`, `menit`, `detik`, `lamaPakan`, `kecepatan`) VALUES
(1, 13, 25, 10, 30000, 80),
(2, 14, 9, 0, 30000, 100),
(3, 15, 0, 0, 30000, 100),
(4, 18, 0, 0, 30000, 100);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `monitoring`
--
ALTER TABLE `monitoring`
  ADD PRIMARY KEY (`id_kondisi`);

--
-- Indexes for table `waktukasihpakan`
--
ALTER TABLE `waktukasihpakan`
  ADD PRIMARY KEY (`id_waktuMakan`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `monitoring`
--
ALTER TABLE `monitoring`
  MODIFY `id_kondisi` int(100) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=91;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
