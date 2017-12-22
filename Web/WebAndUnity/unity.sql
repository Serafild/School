-- phpMyAdmin SQL Dump
-- version 4.4.12
-- http://www.phpmyadmin.net
--
-- Client :  127.0.0.1
-- Généré le :  Ven 12 Mai 2017 à 22:40
-- Version du serveur :  5.5.42
-- Version de PHP :  5.5.27

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `unity`
--

-- --------------------------------------------------------

--
-- Structure de la table `token`
--

CREATE TABLE IF NOT EXISTS `token` (
  `id` int(11) NOT NULL,
  `value` varchar(255) NOT NULL,
  `expiration` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `apikey` varchar(255) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `token`
--

INSERT INTO `token` (`id`, `value`, `expiration`, `apikey`) VALUES
(15, 'aea9789988c08f28538422f1c3427388', '2017-04-13 01:23:24', 'harambart'),
(16, '1ca4dffd6cb96dfe66f1a044d3bb7cfb', '2017-05-09 18:30:30', 'harambart'),
(17, '3cdb82a314eeef6d77aa4cbacb7280dd', '2017-05-12 18:29:04', 'harambart'),
(18, 'e35adc826b021f91f72f183d1bb24773', '2017-05-11 01:14:48', 'harambart'),
(19, '810bf83c7adfd8a04ac1f11508bab9e0', '2017-05-03 01:24:25', 'harambart'),
(20, '4e0d67e54ad6626e957d15b08ae128a6', '2017-05-02 01:25:08', 'harambart'),
(21, '24bb26bb300eefd5ecd1373e002d8df5', '2017-05-02 01:41:52', 'harambart');

-- --------------------------------------------------------

--
-- Structure de la table `user`
--

CREATE TABLE IF NOT EXISTS `user` (
  `id` int(11) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `score` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;

--
-- Contenu de la table `user`
--

INSERT INTO `user` (`id`, `username`, `password`, `score`) VALUES
(4, 'admin', '21232f297a57a5a743894a0e4a801fc3', 350),
(5, 'test1', '5a105e8b9d40e1329780d62ea2265d8a', 2),
(6, 'test2', 'ad0234829205b9033196ba818f7a872b', 3),
(7, 'test3', '8ad8757baa8564dc136c1e07507f4a98', 4);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `token`
--
ALTER TABLE `token`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `token`
--
ALTER TABLE `token`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=22;
--
-- AUTO_INCREMENT pour la table `user`
--
ALTER TABLE `user`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=8;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
