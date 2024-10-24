/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IFont
*/

#ifndef IFONT_HPP_
#define IFONT_HPP_

namespace LE {
    class IFont {
        public:
            virtual ~IFont() = default;

            virtual void init();

        protected:
    };
}

#endif /* !IFONT_HPP_ */
