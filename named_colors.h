#pragma once


//
//   This file was created by Thomas Carrel.
//   https://www.github.com/tcarrel
// 
//   Options:          
//   +----------------------------+---------------------------------------------------------------------+--------------+
//   | Define                     | Effect                                                              | Recommended? |
//   +============================+=====================================================================+==============+
//   | NAMED_COLORS_PREFER_ENUM   | Colors are defined in an enum class instead of constexpr uint32_ts. | No           |
//   +----------------------------+---------------------------------------------------------------------+--------------+
//   | NAMED_COLORS_ENABLE_TUPLES | Colors are additionally defined as tuples.  See below.              | Maybe        |
//   +----------------------------+---------------------------------------------------------------------+--------------+
// 
//      Names of colors defined in either an enum class (hereafter just enum) or a bunch of constexpr uint32_t's.
//    uint32_t's is the default.  The uint32_t's are all in the namespace hex_color and the enum's name is also
//    hex_color so it should be fairly simple to switch between the two in your application.
// 
//      All colors have their alpha channel set 255 or 1.0 (fully opaque) by default.  This can, of course, be easily
//    modified when the colors are used.
// 
//      To use the enum and disable the uint32_t's, #define NAMED_COLORS_PREFER_ENUM before including
//    this file.  The enums do require casting into uint32_t's before doing any arithmatic with them like altering
//    the alpha values so uint32_t's is the default and are generally easier to work with in most cases.
// 
//      Additionally, by defining NAMED_COLORS_ENABLE_TUPLES before including this file, each color will also
//    be defined (in the global namespace) as a tuple of four doubles with seperate r, g, b, a values as
//    normalized [0.0-1.0] doubles.  (In the order R, G, B, then A.)  If these were defined but not used the compiler
//    will likely remove them anyway however, they are really most useful like this for use in 3D graphics applications.
// 
//    In the future, I may make it glm::vec4's be an option as well or replace the tuples with them instead.
//   
//      Color names were taken from
//    < https://en.wikipedia.org/wiki/List_of_colors:_A%E2%80%93F >,
//    < https://en.wikipedia.org/wiki/List_of_colors:_G%E2%80%93M >,
//    < https://en.wikipedia.org/wiki/List_of_colors:_N%E2%80%93Z >, and
//    < https://en.wikipedia.org/wiki/Pantone_448_C >
//    on October 30, 2021.  This is only as accurate and complete as those lists were at that time.  It was, however,
//    necessary--for obvious reasons--to alter many of the names to make the work in C++.  The following is an explanation
//    of how I've gone about this:
// 
//    1)  All color names are constants and therefore are in all capital letters.  See example 1 below.
//    2)  All spaces and punctuation unless otherwise noted is replace with underscores (_).  If this would result in multiple
//          consecutive underscores, only one is used to avoid UB.  See example 1 below.
//    3)  There are no examples of this so far, however, in the event that the above changes result in a color name
//          beginning with an underscore, it is to be removed.  _HELLO  --> HELLO
//    4)  Apostrophes (') used for to show posession in English are remove and no underscore is added.
//          Apostrophes used for contractions and other purposes are replaced with an underscore.  See examples 2 and 3 below.
//    5)  If some puntuation is used to represend a commonly used word, like ampersand (&) or the number symbol (#) the
//          appropriate word is used instead.  See example 4 below.
//    6)  The Wikipedia articles list some colors with alternate names given parenthetically in the name field of the table.
//          In this case, all possible names are defined with the same color value.
//    7)  In some rare cases because of cultural or geographic difference, there are more than one color with the same name.
//          All the colors will be defined with the same name and the name appended with _# where the # is replaced by number
//          starting from one and ascending for each color with the same name.  Use [ctrl+f] or your equivilant and search for
//          VERMILION in this file for an example of this.
// 
//    +---+----------------------+---------------------+
//    | # | Name as on Wikipedia | Name as used here   |
//    +===+======================+=====================+
//    | 1 | Absolute Zero        | ABSOLUTE_ZERO       |
//    +---+----------------------+---------------------+
//    | 2 | Davy's grey          | DAVYS_GREY          |
//    +---+----------------------+---------------------+
//    | 3 | B'dazzled blue       | B_DAZZLED_BLUE      |
//    +---+----------------------+---------------------+
//    | 4 | Olive Drab #7        | OLIVE_DRAB_NUMBER_7 |
//    +---+----------------------+---------------------+
// 
//   Feel free
//    to add colors and submit them as pull request if you like.
//



#include<cstdint>



#if defined(NAMED_COLORS_PREFER_ENUM)
enum class hex_color : uint32_t
{
    ABSOLUTE_ZERO                           = 0x00'48'BA'ff,
    ACID_GREEN                              = 0xB0'BF'1A'ff,
    AERO                                    = 0x7C'B9'E8'ff,
    AERO_BLUE                               = 0xC0'E8'D5'ff,
    AFRICAN_VIOLET                          = 0xB2'84'BE'ff,
    AIR_SUPERIORITY_BLUE                    = 0x72'A0'C1'ff,
    ALABASTER                               = 0xED'EA'E0'ff,
    ALICE_BLUE                              = 0xF0'F8'FF'ff,
    ALLOY_ORANGE                            = 0xC4'62'10'ff,
    ALMOND                                  = 0xEF'DE'CD'ff,
    AMARANTH                                = 0xE5'2B'50'ff,
    AMARANTH_M_AND_P                        = 0x9F'2B'68'ff,
    AMARANTH_PINK                           = 0xF1'9C'BB'ff,
    AMARANTH_PURPLE                         = 0xAB'27'4F'ff,
    AMARANTH_RED                            = 0xD3'21'2D'ff,
    AMAZON                                  = 0x3B'7A'57'ff,
    AMBER                                   = 0xFF'BF'00'ff,
    AMBER_SAE                               = 0xFF'7E'00'ff,
    AMBER_ECE                               = 0xFF'7E'00'ff,
    AMETHYST                                = 0x99'66'CC'ff,
    ANDROID_GREEN                           = 0x3D'DC'84'ff,
    ANTIQUE_BRASS                           = 0xCD'95'75'ff,
    ANTIQUE_BRONZE                          = 0x66'5D'1E'ff,
    ANTIQUE_FUCHSIA                         = 0x91'5C'83'ff,
    ANTIQUE_RUBY                            = 0x84'1B'2D'ff,
    ANTIQUE_WHITE                           = 0xFA'EB'D7'ff,
    AO                                      = 0x00'80'00'ff,
    APPLE_GREEN                             = 0x8D'B6'00'ff,
    APRICOT                                 = 0xFB'CE'B1'ff,
    AQUA                                    = 0x00'FF'FF'ff,
    AQUAMARINE                              = 0x7F'FF'D4'ff,
    ARCTIC_LIME                             = 0xD0'FF'14'ff,
    ARMY_GREEN                              = 0x4B'53'20'ff,
    ARTICHOKE                               = 0x8F'97'79'ff,
    ARYLIDE_YELLOW                          = 0xE9'D6'6B'ff,
    ASH_GRAY                                = 0xB2'BE'B5'ff,
    ASPARAGUS                               = 0x87'A9'6B'ff,
    ATOMIC_TANGERINE                        = 0xFF'99'66'ff,
    AUBURN                                  = 0xA5'2A'2A'ff,
    AUREOLIN                                = 0xFD'EE'00'ff,
    AVOCADO                                 = 0x56'82'03'ff,
    AZURE                                   = 0x00'7F'FF'ff,
    AZURE_X11                               = 0xF0'FF'FF'ff,
    AZURE_WEB                               = 0xF0'FF'FF'ff,
    BABY_BLUE                               = 0x89'CF'F0'ff,
    BABY_BLUE_EYES                          = 0xA1'CA'F1'ff,
    BABY_PINK                               = 0xF4'C2'C2'ff,
    BABY_POWDER                             = 0xFE'FE'FA'ff,
    BAKER_MILLER_PINK                       = 0xFF'91'AF'ff,
    BANANA_MANIA                            = 0xFA'E7'B5'ff,
    BARBIE_PINK                             = 0xDA'18'84'ff,
    BARN_RED                                = 0x7C'0A'02'ff,
    BATTLESHIP_GREY                         = 0x84'84'82'ff,
    BEAU_BLUE                               = 0xBC'D4'E6'ff,
    BEAVER                                  = 0x9F'81'70'ff,
    BEIGE                                   = 0xF5'F5'DC'ff,
    B_DAZZLED_BLUE                          = 0x2E'58'94'ff,
    BIG_DIP_O_RUBY                          = 0x9C'25'42'ff,
    BISQUE                                  = 0xFF'E4'C4'ff,
    BISTRE                                  = 0x3D'2B'1F'ff,
    BISTRE_BROWN                            = 0x96'71'17'ff,
    BITTER_LEMON                            = 0xCA'E0'0D'ff,
    BITTER_LIME                             = 0xBF'FF'00'ff,
    BITTERSWEET                             = 0xFE'6F'5E'ff,
    BITTERSWEET_SHIMMER                     = 0xBF'4F'51'ff,
    BLACK                                   = 0x00'00'00'ff,
    BLACK_BEAN                              = 0x3D'0C'02'ff,
    BLACK_CHOCOLATE                         = 0x1B'18'11'ff,
    BLACK_COFFEE                            = 0x3B'2F'2F'ff,
    BLACK_CORAL                             = 0x54'62'6F'ff,
    BLACK_OLIVE                             = 0x3B'3C'36'ff,
    BLACK_SHADOWS                           = 0xBF'AF'B2'ff,
    BLANCHED_ALMOND                         = 0xFF'EB'CD'ff,
    BLAST_OFF_BRONZE                        = 0xA5'71'64'ff,
    BLEU_DE_FRANCE                          = 0x31'8C'E7'ff,
    BLIZZARD_BLUE                           = 0xAC'E5'EE'ff,
    BLOND                                   = 0xFA'F0'BE'ff,
    BLOOD_RED                               = 0x66'00'00'ff,
    BLUE                                    = 0x00'00'FF'ff,
    BLUE_CRAYOLA                            = 0x1F'75'FE'ff,
    BLUE_MUNSELL                            = 0x00'93'AF'ff,
    BLUE_NCS                                = 0x00'87'BD'ff,
    BLUE_PANTONE                            = 0x00'18'A8'ff,
    BLUE_PIGMENT                            = 0x33'33'99'ff,
    BLUE_RYB                                = 0x02'47'FE'ff,
    BLUE_BELL                               = 0xA2'A2'D0'ff,
    BLUE_GRAY                               = 0x66'99'CC'ff,
    BLUE_GREEN                              = 0x0D'98'BA'ff,
    BLUE_GREEN_COLOR_WHEEL                  = 0x06'4E'40'ff,
    BLUE_JEANS                              = 0x5D'AD'EC'ff,
    BLUE_SAPPHIRE                           = 0x12'61'80'ff,
    BLUE_VIOLET                             = 0x8A'2B'E2'ff,
    BLUE_VIOLET_CRAYOLA                     = 0x73'66'BD'ff,
    BLUE_VIOLET_COLOR_WHEEL                 = 0x4D'1A'7F'ff,
    BLUE_YONDER                             = 0x50'72'A7'ff,
    BLUETIFUL                               = 0x3C'69'E7'ff,
    BLUSH                                   = 0xDE'5D'83'ff,
    BOLE                                    = 0x79'44'3B'ff,
    BONE                                    = 0xE3'DA'C9'ff,
    BOTTLE_GREEN                            = 0x00'6A'4E'ff,
    BRANDY                                  = 0x87'41'3F'ff,
    BRICK_RED                               = 0xCB'41'54'ff,
    BRIGHT_GREEN                            = 0x66'FF'00'ff,
    BRIGHT_LILAC                            = 0xD8'91'EF'ff,
    BRIGHT_MAROON                           = 0xC3'21'48'ff,
    BRIGHT_NAVY_BLUE                        = 0x19'74'D2'ff,
    BRIGHT_YELLOW_CRAYOLA                   = 0xFF'AA'1D'ff,
    BRILLIANT_ROSE                          = 0xFF'55'A3'ff,
    BRINK_PINK                              = 0xFB'60'7F'ff,
    BRITISH_RACING_GREEN                    = 0x00'42'25'ff,
    BRONZE                                  = 0xCD'7F'32'ff,
    BROWN                                   = 0x88'54'0B'ff,
    BROWN_SUGAR                             = 0xAF'6E'4D'ff,
    BRUNSWICK_GREEN                         = 0x1B'4D'3E'ff,
    BUD_GREEN                               = 0x7B'B6'61'ff,
    BUFF                                    = 0xFF'C6'80'ff,
    BURGUNDY                                = 0x80'00'20'ff,
    BURLYWOOD                               = 0xDE'B8'87'ff,
    BURNISHED_BROWN                         = 0xA1'7A'74'ff,
    BURNT_ORANGE                            = 0xCC'55'00'ff,
    BURNT_SIENNA                            = 0xE9'74'51'ff,
    BURNT_UMBER                             = 0x8A'33'24'ff,
    BYZANTINE                               = 0xBD'33'A4'ff,
    BYZANTIUM                               = 0x70'29'63'ff,
    CADET                                   = 0x53'68'72'ff,
    CADET_BLUE                              = 0x5F'9E'A0'ff,
    CADET_BLUE_CRAYOLA                      = 0xA9'B2'C3'ff,
    CADET_GREY                              = 0x91'A3'B0'ff,
    CADMIUM_GREEN                           = 0x00'6B'3C'ff,
    CADMIUM_ORANGE                          = 0xED'87'2D'ff,
    CADMIUM_RED                             = 0xE3'00'22'ff,
    CADMIUM_YELLOW                          = 0xFF'F6'00'ff,
    CAFÉ_AU_LAIT                            = 0xA6'7B'5B'ff,
    CAFE_AU_LAIT                            = 0xA6'7B'5B'ff,
    CAFÉ_NOIR                               = 0x4B'36'21'ff,
    CAFE_NOIR                               = 0x4B'36'21'ff,
    CAMBRIDGE_BLUE                          = 0xA3'C1'AD'ff,
    CAMEL                                   = 0xC1'9A'6B'ff,
    CAMEO_PINK                              = 0xEF'BB'CC'ff,
    CANARY                                  = 0xFF'FF'99'ff,
    CANARY_YELLOW                           = 0xFF'EF'00'ff,
    CANDY_APPLE_RED                         = 0xFF'08'00'ff,
    CANDY_PINK                              = 0xE4'71'7A'ff,
    CAPRI                                   = 0x00'BF'FF'ff,
    CAPUT_MORTUUM                           = 0x59'27'20'ff,
    CARDINAL                                = 0xC4'1E'3A'ff,
    CARIBBEAN_GREEN                         = 0x00'CC'99'ff,
    CARMINE                                 = 0x96'00'18'ff,
    CARMINE_M_AND_P                         = 0xD7'00'40'ff,
    CARNATION_PINK                          = 0xFF'A6'C9'ff,
    CARNELIAN                               = 0xB3'1B'1B'ff,
    CAROLINA_BLUE                           = 0x56'A0'D3'ff,
    CARROT_ORANGE                           = 0xED'91'21'ff,
    CASTLETON_GREEN                         = 0x00'56'3F'ff,
    CATAWBA                                 = 0x70'36'42'ff,
    CEDAR_CHEST                             = 0xC9'5A'49'ff,
    CELADON                                 = 0xAC'E1'AF'ff,
    CELADON_BLUE                            = 0x00'7B'A7'ff,
    CELADON_GREEN                           = 0x2F'84'7C'ff,
    CELESTE                                 = 0xB2'FF'FF'ff,
    CELTIC_BLUE                             = 0x24'6B'CE'ff,
    CERISE                                  = 0xDE'31'63'ff,
    CERULEAN                                = 0x00'7B'A7'ff,
    CERULEAN_BLUE                           = 0x2A'52'BE'ff,
    CERULEAN_FROST                          = 0x6D'9B'C3'ff,
    CERULEAN_CRAYOLA                        = 0x1D'AC'D6'ff,
    CG_BLUE                                 = 0x00'7A'A5'ff,
    CG_RED                                  = 0xE0'3C'31'ff,
    CHAMPAGN                                = 0xF7'E7'CE'ff,
    CHAMPAGNE_PINK                          = 0xF1'DD'CF'ff,
    CHARCOAL                                = 0x36'45'4F'ff,
    CHARLESTON_GREEN                        = 0x23'2B'2B'ff,
    CHARM_PINK                              = 0xE6'8F'AC'ff,
    CHARTREUSE_TRADITIONAL                  = 0xDF'FF'00'ff,
    CHARTREUSE_WEB                          = 0x7F'FF'00'ff,
    CHERRY_BLOSSOM_PINK                     = 0xFF'B7'C5'ff,
    CHESTNUT                                = 0x95'45'35'ff,
    CHILI_RED                               = 0xE2'3D'28'ff,
    CHINA_PINK                              = 0xDE'6F'A1'ff,
    CHINA_ROSE                              = 0xA8'51'6E'ff,
    CHINESE_RED                             = 0xAA'38'1E'ff,
    CHINESE_VIOLET                          = 0x85'60'88'ff,
    CHINESE_YELLOW                          = 0xFF'B2'00'ff,
    CHOCOLATE_TRADITIONAL                   = 0x7B'3F'00'ff,
    CHOCOLATE_WEB                           = 0xD2'69'1E'ff,
    CHOCOLATE_COSMOS                        = 0x58'11'1A'ff,
    CHROME_YELLOW                           = 0xFF'A7'00'ff,
    CINEREOUS                               = 0x98'81'7B'ff,
    CINNABAR                                = 0xE3'42'34'ff,
    CINNAMON_SATIN                          = 0xCD'60'7E'ff,
    CITRINE                                 = 0xE4'D0'0A'ff,
    CITRON                                  = 0x9F'A9'1F'ff,
    CLARET                                  = 0x7F'17'34'ff,
    COBALT_BLUE                             = 0x00'47'AB'ff,
    COCOA_BROWN                             = 0xD2'69'1E'ff,
    COFFEE                                  = 0x6F'4E'37'ff,
    COLUMBIA_BLUE                           = 0xB9'D9'EB'ff,
    CONGO_PINK                              = 0xF8'83'79'ff,
    COOL_GREY                               = 0x8C'92'AC'ff,
    COPPER                                  = 0xB8'73'33'ff,
    COPPER_CRAYOLA                          = 0xDA'8A'67'ff,
    COPPER_PENNY                            = 0xAD'6F'69'ff,
    COPPER_RED                              = 0xCB'6D'51'ff,
    COPPER_ROSE                             = 0x99'66'66'ff,
    COQUELICOT                              = 0xFF'38'00'ff,
    CORAL                                   = 0xFF'7F'50'ff,
    CORAL_PINK                              = 0xF8'83'79'ff,
    CORDOVAN                                = 0x89'3F'45'ff,
    CORN                                    = 0xFB'EC'5D'ff,
    CORNELL_RED                             = 0xB3'1B'1B'ff,
    CORNFLOWER_BLUE                         = 0x64'95'ED'ff,
    CORNSILK                                = 0xFF'F8'DC'ff,
    COSMIC_COBALT                           = 0x2E'2D'88'ff,
    COSMIC_LATTE                            = 0xFF'F8'E7'ff,
    COYOTE_BROWN                            = 0x81'61'3C'ff,
    COTTON_CANDY                            = 0xFF'BC'D9'ff,
    CREAM                                   = 0xFF'FD'D0'ff,
    CRIMSON                                 = 0xDC'14'3C'ff,
    CRIMSON_UA                              = 0x9E'1B'32'ff,
    CRYSTAL                                 = 0xA7'D8'DE'ff,
    CULTURED                                = 0xF5'F5'F5'ff,
    CYAN                                    = 0x00'FF'FF'ff,
    CYAN_PROCESS                            = 0x00'B7'EB'ff,
    CYBER_GRAPE                             = 0x58'42'7C'ff,
    CYBER_YELLOW                            = 0xFF'D3'00'ff,
    CYCLAMEN                                = 0xF5'6F'A1'ff,
    DARK_BLUE_GRAY                          = 0x66'66'99'ff,
    DARK_BROWN                              = 0x65'43'21'ff,
    DARK_BYZANTIUM                          = 0x5D'39'54'ff,
    DARK_CORNFLOWER_BLUE                    = 0x26'42'8B'ff,
    DARK_CYAN                               = 0x00'8B'8B'ff,
    DARK_ELECTRIC_BLUE                      = 0x53'68'78'ff,
    DARK_GOLDENROD                          = 0xB8'86'0B'ff,
    DARK_GREEN                              = 0x01'32'20'ff,
    DARK_GREEN_X11                          = 0x00'64'00'ff,
    DARK_JUNGLE_GREEN                       = 0x1A'24'21'ff,
    DARK_KHAKI                              = 0xBD'B7'6B'ff,
    DARK_LAVA                               = 0x48'3C'32'ff,
    DARK_LIVER                              = 0x53'4B'4F'ff,
    DARK_LIVER_HORSES                       = 0x54'3D'37'ff,
    DARK_MAGENTA                            = 0x8B'00'8B'ff,
    DARK_MOSS_GREEN                         = 0x4A'5D'23'ff,
    DARK_OLIVE_GREEN                        = 0x55'6B'2F'ff,
    DARK_ORANGE                             = 0xFF'8C'00'ff,
    DARK_ORCHID                             = 0x99'32'CC'ff,
    DARK_PASTEL_GREEN                       = 0x03'C0'3C'ff,
    DARK_PURPLE                             = 0x30'19'34'ff,
    DARK_RED                                = 0x8B'00'00'ff,
    DARK_SALMON                             = 0xE9'96'7A'ff,
    DARK_SEA_GREEN                          = 0x8F'BC'8F'ff,
    DARK_SIENNA                             = 0x3C'14'14'ff,
    DARK_SKY_BLUE                           = 0x8C'BE'D6'ff,
    DARK_SLATE_BLUE                         = 0x48'3D'8B'ff,
    DARK_SLATE_GRAY                         = 0x2F'4F'4F'ff,
    DARK_SPRING_GREEN                       = 0x17'72'45'ff,
    DARK_TURQUOISE                          = 0x00'CE'D1'ff,
    DARK_VIOLET                             = 0x94'00'D3'ff,
    DARTMOUTH_GREEN                         = 0x00'70'3C'ff,
    DAVYS_GREY                              = 0x55'55'55'ff,
    DEEP_CERISE                             = 0xDA'32'87'ff,
    DEEP_CHAMPAGNE                          = 0xFA'D6'A5'ff,
    DEEP_CHESTNUT                           = 0xB9'4E'48'ff,
    DEEP_JUNGLE_GREEN                       = 0x00'4B'49'ff,
    DEEP_PINK                               = 0xFF'14'93'ff,
    DEEP_SAFFRON                            = 0xFF'99'33'ff,
    DEEP_SKY_BLUE                           = 0x00'BF'FF'ff,
    DEEP_SPACE_SPARKLE                      = 0x4A'64'6C'ff,
    DEEP_TAUPE                              = 0x7E'5E'60'ff,
    DENIM                                   = 0x15'60'BD'ff,
    DENIM_BLUE                              = 0x22'43'B6'ff,
    DESERT                                  = 0xC1'9A'6B'ff,
    DESERT_SAND                             = 0xED'C9'AF'ff,
    DIM_GRAY                                = 0x69'69'69'ff,
    DODGER_BLUE                             = 0x1E'90'FF'ff,
    DOGWOOD_ROSE                            = 0xD7'18'68'ff,
    DRAB                                    = 0x96'71'17'ff,
    DUKE_BLUE                               = 0x00'00'9C'ff,
    DUTCH_WHITE                             = 0xEF'DF'BB'ff,
    EARTH_YELLOW                            = 0xE1'A9'5F'ff,
    EBONY                                   = 0x55'5D'50'ff,
    ECRU                                    = 0xC2'B2'80'ff,
    EERIE_BLACK                             = 0x1B'1B'1B'ff,
    EGGPLANT                                = 0x61'40'51'ff,
    EGGSHELL                                = 0xF0'EA'D6'ff,
    EGYPTIAN_BLUE                           = 0x10'34'A6'ff,
    EIGENGRAU                               = 0x16'16'1D'ff,
    ELECTRIC_BLUE                           = 0x7D'F9'FF'ff,
    ELECTRIC_GREEN                          = 0x00'FF'00'ff,
    ELECTRIC_INDIGO                         = 0x6F'00'FF'ff,
    ELECTRIC_LIME                           = 0xCC'FF'00'ff,
    ELECTRIC_PURPLE                         = 0xBF'00'FF'ff,
    ELECTRIC_VIOLET                         = 0x8F'00'FF'ff,
    EMERALD                                 = 0x50'C8'78'ff,
    EMINENCE                                = 0x6C'30'82'ff,
    ENGLISH_GREEN                           = 0x1B'4D'3E'ff,
    ENGLISH_LAVENDER                        = 0xB4'83'95'ff,
    ENGLISH_RED                             = 0xAB'4B'52'ff,
    ENGLISH_VERMILLION                      = 0xCC'47'4B'ff,
    ENGLISH_VIOLET                          = 0x56'3C'5C'ff,
    ERIN                                    = 0x00'FF'40'ff,
    ETON_BLUE                               = 0x96'C8'A2'ff,
    FALLOW                                  = 0xC1'9A'6B'ff,
    FALU_RED                                = 0x80'18'18'ff,
    FANDANGO                                = 0xB5'33'89'ff,
    FANDANGO_PINK                           = 0xDE'52'85'ff,
    FASHION_FUCHSIA                         = 0xF4'00'A1'ff,
    FAWN                                    = 0xE5'AA'70'ff,
    FELDGRAU                                = 0x4D'5D'53'ff,
    FERN_GREEN                              = 0x4F'79'42'ff,
    FIELD_DRAB                              = 0x6C'54'1E'ff,
    FIERY_ROSE                              = 0xFF'54'70'ff,
    FIREBRICK                               = 0xB2'22'22'ff,
    FIRE_ENGINE_RED                         = 0xCE'20'29'ff,
    FIRE_OPAL                               = 0xE9'5C'4B'ff,
    FLAME                                   = 0xE2'58'22'ff,
    FLAX                                    = 0xEE'DC'82'ff,
    FLIRT                                   = 0xA2'00'6D'ff,
    FLORAL_WHITE                            = 0xFF'FA'F0'ff,
    FLUORESCENT_BLUE                        = 0x15'F4'EE'ff,
    FOREST_GREEN_CRAYOLA                    = 0x5F'A7'77'ff,
    FOREST_GREEN_TRADITIONAL                = 0x01'44'21'ff,
    FOREST_GREEN_WEB                        = 0x22'8B'22'ff,
    FRENCH_BEIGE                            = 0xA6'7B'5B'ff,
    FRENCH_BISTRE                           = 0x85'6D'4D'ff,
    FRENCH_BLUE                             = 0x00'72'BB'ff,
    FRENCH_FUCHSIA                          = 0xFD'3F'92'ff,
    FRENCH_LILAC                            = 0x86'60'8E'ff,
    FRENCH_LIME                             = 0x9E'FD'38'ff,
    FRENCH_MAUVE                            = 0xD4'73'D4'ff,
    FRENCH_PINK                             = 0xFD'6C'9E'ff,
    FRENCH_RASPBERRY                        = 0xC7'2C'48'ff,
    FRENCH_ROSE                             = 0xF6'4A'8A'ff,
    FRENCH_SKY_BLUE                         = 0x77'B5'FE'ff,
    FRENCH_VIOLET                           = 0x88'06'CE'ff,
    FROSTBITE                               = 0xE9'36'A7'ff,
    FUCHSIA                                 = 0xFF'00'FF'ff,
    FUCHSIA_CRAYOLA                         = 0xC1'54'C1'ff,
    FUCHSIA_PURPLE                          = 0xCC'39'7B'ff,
    FUCHSIA_ROSE                            = 0xC7'43'75'ff,
    FULVOUS                                 = 0xE4'84'00'ff,
    FUZZY_WUZZY                             = 0x87'42'1F'ff,
    GAINSBORO                               = 0xDC'DC'DC'ff,
    GAMBOGE                                 = 0xE4'9B'0F'ff,
    GENERIC_VIRIDIAN                        = 0x00'7F'66'ff,
    GHOST_WHITE                             = 0xF8'F8'FF'ff,
    GLAUCOUS                                = 0x60'82'B6'ff,
    GLOSSY_GRAPE                            = 0xAB'92'B3'ff,
    GO_GREEN                                = 0x00'AB'66'ff,
    GOLD                                    = 0xA5'7C'00'ff,
    GOLD_METALLIC                           = 0xD4'AF'37'ff,
    GOLDEN                                  = 0xFF'D7'00'ff,
    GOLD_WEB                                = 0xFF'D7'00'ff,
    GOLD_CRAYOLA                            = 0xE6'BE'8A'ff,
    GOLD_FUSION                             = 0x85'75'4E'ff,
    GOLDEN_BROWN                            = 0x99'65'15'ff,
    GOLDEN_POPPY                            = 0xFC'C2'00'ff,
    GOLDEN_YELLOW                           = 0xFF'DF'00'ff,
    GOLDENROD                               = 0xDA'A5'20'ff,
    GOTHAM_GREEN                            = 0x00'57'3F'ff,
    GRANITE_GRAY                            = 0x67'67'67'ff,
    GRANNY_SMITH_APPLE                      = 0xA8'E4'A0'ff,
    GRAY                                    = 0xBE'BE'BE'ff,
    GRAY_WEB                                = 0x80'80'80'ff,
    GRAY_X11                                = 0x80'80'80'ff,
    GREY                                    = 0x80'80'80'ff,
    GREEN                                   = 0x00'FF'00'ff,
    GREEN_CRAYOLA                           = 0x1C'AC'78'ff,
    GREEN_WEB                               = 0x00'80'00'ff,
    GREEN_MUNSELL                           = 0x00'A8'77'ff,
    GREEN_NCS                               = 0x00'9F'6B'ff,
    GREEN_PANTONE                           = 0x00'AD'43'ff,
    GREEN_PIGMENT                           = 0x00'A5'50'ff,
    GREEN_RYB                               = 0x66'B0'32'ff,
    GREEN_BLUE                              = 0x11'64'B4'ff,
    GREEN_BLUE_CRAYOLA                      = 0x28'87'C8'ff,
    GREEN_CYAN                              = 0x00'99'66'ff,
    GREEN_LIZARD                            = 0xA7'F4'32'ff,
    GREEN_SHEEN                             = 0x6E'AE'A1'ff,
    GREEN_YELLOW                            = 0xAD'FF'2F'ff,
    GREEN_YELLOW_CRAYOLA                    = 0xF0'E8'91'ff,
    GRULLO                                  = 0xA9'9A'86'ff,
    GUNMETAL                                = 0x2A'34'39'ff,
    HAN_BLUE                                = 0x44'6C'CF'ff,
    HAN_PURPLE                              = 0x52'18'FA'ff,
    HANSA_YELLOW                            = 0xE9'D6'6B'ff,
    HARLEQUIN                               = 0x3F'FF'00'ff,
    HARVEST_GOLD                            = 0xDA'91'00'ff,
    HEAT_WAVE                               = 0xFF'7A'00'ff,
    HELIOTROPE                              = 0xDF'73'FF'ff,
    HELIOTROPE_GRAY                         = 0xAA'98'A9'ff,
    HOLLYWOOD_CERISE                        = 0xF4'00'A1'ff,
    HONEYDEW                                = 0xF0'FF'F0'ff,
    HONOLULU_BLUE                           = 0x00'6D'B0'ff,
    HOOKERS_GREEN                           = 0x49'79'6B'ff,
    HOT_MAGENTA                             = 0xFF'1D'CE'ff,
    HOT_PINK                                = 0xFF'69'B4'ff,
    HUNTER_GREEN                            = 0x35'5E'3B'ff,
    ICEBERG                                 = 0x71'A6'D2'ff,
    ICTERINE                                = 0xFC'F7'5E'ff,
    ILLUMINATING_EMERALD                    = 0x31'91'77'ff,
    IMPERIAL_RED                            = 0xED'29'39'ff,
    INCHWORM                                = 0xB2'EC'5D'ff,
    INDEPENDENCE                            = 0x4C'51'6D'ff,
    INDIA_GREEN                             = 0x13'88'08'ff,
    INDIAN_RED                              = 0xCD'5C'5C'ff,
    INDIAN_YELLOW                           = 0xE3'A8'57'ff,
    INDIGO                                  = 0x4B'00'82'ff,
    INDIGO_DYE                              = 0x00'41'6A'ff,
    INTERNATIONAL_KLEIN_BLUE                = 0x13'0A'8F'ff,
    INTERNATIONAL_ORANGE_AEROSPACE          = 0xFF'4F'00'ff,
    INTERNATIONAL_ORANGE_ENGINEERING        = 0xBA'16'0C'ff,
    INTERNATIONAL_ORANGE_GOLDEN_GATE_BRIDGE = 0xC0'36'2C'ff,
    GOLDEN_GATE_BRIDGE_RED                  = 0xC0'36'2C'ff,
    IRIS                                    = 0x5A'4F'CF'ff,
    IRRESISTIBLE                            = 0xB3'44'6C'ff,
    ISABELLINE                              = 0xF4'F0'EC'ff,
    ITALIAN_SKY_BLUE                        = 0xB2'FF'FF'ff,
    IVORY                                   = 0xFF'FF'F0'ff,
    JADE                                    = 0x00'A8'6B'ff,
    JAPANESE_CARMINE                        = 0x9D'29'33'ff,
    JAPANESE_VIOLET                         = 0x5B'32'56'ff,
    JASMINE                                 = 0xF8'DE'7E'ff,
    JAZZBERRY_JAM                           = 0xA5'0B'5E'ff,
    JET                                     = 0x34'34'34'ff,
    JONQUIL                                 = 0xF4'CA'16'ff,
    JUNE_BUD                                = 0xBD'DA'57'ff,
    JUNGLE_GREEN                            = 0x29'AB'87'ff,
    KELLY_GREEN                             = 0x4C'BB'17'ff,
    KEPPEL                                  = 0x3A'B0'9E'ff,
    KEY_LIME                                = 0xE8'F4'8C'ff,
    KHAKI_WEB                               = 0xC3'B0'91'ff,
    KHAKI_X11                               = 0xF0'E6'8C'ff,
    KOBE                                    = 0x88'2D'17'ff,
    KOBI                                    = 0xE7'9F'C4'ff,
    KOBICHA                                 = 0x6B'44'23'ff,
    KOMBU_GREEN                             = 0x35'42'30'ff,
    KSU_PURPLE                              = 0x51'28'88'ff,
    LANGUID_LAVENDER                        = 0xD6'CA'DD'ff,
    LAPIS_LAZULI                            = 0x26'61'9C'ff,
    LASER_LEMON                             = 0xFF'FF'66'ff,
    LAUREL_GREEN                            = 0xA9'BA'9D'ff,
    LAVA                                    = 0xCF'10'20'ff,
    LAVENDER_FLORAL                         = 0xB5'7E'DC'ff,
    LAVENDER_WEB                            = 0xE6'E6'FA'ff,
    LAVENDER_BLUE                           = 0xCC'CC'FF'ff,
    LAVENDER_BLUSH                          = 0xFF'F0'F5'ff,
    LAVENDER_GRAY                           = 0xC4'C3'D0'ff,
    LAWN_GREEN                              = 0x7C'FC'00'ff,
    LEMON                                   = 0xFF'F7'00'ff,
    LEMON_CHIFFON                           = 0xFF'FA'CD'ff,
    LEMON_CURRY                             = 0xCC'A0'1D'ff,
    LEMON_GLACIER                           = 0xFD'FF'00'ff,
    LEMON_MERINGUE                          = 0xF6'EA'BE'ff,
    LEMON_YELLOW                            = 0xFF'F4'4F'ff,
    LEMON_YELLOW_CRAYOLA                    = 0xFF'FF'9F'ff,
    LIBERTY                                 = 0x54'5A'A7'ff,
    LIGHT_BLUE                              = 0xAD'D8'E6'ff,
    LIGHT_CORAL                             = 0xF0'80'80'ff,
    LIGHT_CORNFLOWER_BLUE                   = 0x93'CC'EA'ff,
    LIGHT_CYAN                              = 0xE0'FF'FF'ff,
    LIGHT_FRENCH_BEIGE                      = 0xC8'AD'7F'ff,
    LIGHT_GOLDENROD_YELLOW                  = 0xFA'FA'D2'ff,
    LIGHT_GRAY                              = 0xD3'D3'D3'ff,
    LIGHT_GREEN                             = 0x90'EE'90'ff,
    LIGHT_KHAKI                             = 0x90'EE'90'ff,
    LIGHT_ORANGE                            = 0xFE'D8'B1'ff,
    LIGHT_PERIWINKLE                        = 0xC5'CB'E1'ff,
    LIGHT_PINK                              = 0xFF'B6'C1'ff,
    LIGHT_SALMON                            = 0xFF'A0'7A'ff,
    LIGHT_SEA_GREEN                         = 0x20'B2'AA'ff,
    LIGHT_SKY_BLUE                          = 0x87'CE'FA'ff,
    LIGHT_SLATE_GRAY                        = 0x77'88'99'ff,
    LIGHT_STEEL_BLUE                        = 0xB0'C4'DE'ff,
    LIGHT_YELLOW                            = 0xFF'FF'E0'ff,
    LILAC                                   = 0xC8'A2'C8'ff,
    LILAC_LUSTER                            = 0xAE'98'AA'ff,
    LIME_COLOR_WHEEL                        = 0xBF'FF'00'ff,
    LIME_WEB                                = 0xBF'FF'00'ff,
    LIME_X11                                = 0xBF'FF'00'ff,
    LIME_GREEN                              = 0x32'CD'32'ff,
    LINCOLN_GREEN                           = 0x19'59'05'ff,
    LINEN                                   = 0xFA'F0'E6'ff,
    LION                                    = 0xC1'9A'6B'ff,
    LISERAN_PURPLE                          = 0xDE'6F'A1'ff,
    LITTLE_BOY_BLUE                         = 0x6C'A0'DC'ff,
    LIVER                                   = 0x67'4C'47'ff,
    LIVER_DOGS                              = 0xB8'6D'29'ff,
    LIVER_ORGAN                             = 0x6C'2E'1F'ff,
    LIVER_CHESTNUT                          = 0x98'74'56'ff,
    LIVID                                   = 0x66'99'CC'ff,
    MACARONI_AND_CHEESE                     = 0xFF'BD'88'ff,
    MADDER_LAKE                             = 0xCC'33'36'ff,
    MAGENTA                                 = 0xFF'00'FF'ff,
    MAGENTA_CRAYOLA                         = 0xF6'53'A6'ff,
    MAGENTA_DYE                             = 0xCA'1F'7B'ff,
    MAGENTA_PANTONE                         = 0xD0'41'7E'ff,
    MAGENTA_PROCESS                         = 0xFF'00'90'ff,
    MAGENTA_HAZE                            = 0x9F'45'76'ff,
    MAGIC_MINT                              = 0xAA'F0'D1'ff,
    MAGNOLIA                                = 0xF2'E8'D7'ff,
    MAHOGANY                                = 0xC0'40'00'ff,
    MAIZE                                   = 0xFB'EC'5D'ff,
    MAIZE_CRAYOLA                           = 0xF2'C6'49'ff,
    MAJORELLE_BLUE                          = 0x60'50'DC'ff,
    MALACHITE                               = 0x0B'DA'51'ff,
    MANATEE                                 = 0x97'9A'AA'ff,
    MANDARIN                                = 0xF3'7A'48'ff,
    MANGO                                   = 0xFD'BE'02'ff,
    MANGO_TANGO                             = 0xFF'82'43'ff,
    MANTIS                                  = 0x74'C3'65'ff,
    MARDI_GRAS                              = 0x88'00'85'ff,
    MARIGOLD                                = 0xEA'A2'21'ff,
    MAROON_CRAYOLA                          = 0xC3'21'48'ff,
    MAROON_WEB                              = 0x80'00'00'ff,
    MAROON_X11                              = 0xB0'30'60'ff,
    MAUVE                                   = 0xE0'B0'FF'ff,
    MAUVE_TAUPE                             = 0x91'5F'6D'ff,
    MAUVELOUS                               = 0xEF'98'AA'ff,
    MAXIMUM_BLUE                            = 0x47'AB'CC'ff,
    MAXIMUM_BLUE_GREEN                      = 0x30'BF'BF'ff,
    MAXIMUM_BLUE_PURPLE                     = 0xAC'AC'E6'ff,
    MAXIMUM_GREEN                           = 0x5E'8C'31'ff,
    MAXIMUM_GREEN_YELLOW                    = 0xD9'E6'50'ff,
    MAXIMUM_PURPLE                          = 0x73'33'80'ff,
    MAXIMUM_RED                             = 0xD9'21'21'ff,
    MAXIMUM_RED_PURPLE                      = 0xA6'3A'79'ff,
    MAXIMUM_YELLOW                          = 0xFA'FA'37'ff,
    MAXIMUM_YELLOW_RED                      = 0xF2'BA'49'ff,
    MAY_GREEN                               = 0x4C'91'41'ff,
    MAYA_BLUE                               = 0x73'C2'FB'ff,
    MEDIUM_AQUAMARINE                       = 0x66'DD'AA'ff,
    MEDIUM_BLUE                             = 0x00'00'CD'ff,
    MEDIUM_CANDY_APPLE_RED                  = 0xE2'06'2C'ff,
    MEDIUM_CARMINE                          = 0xAF'40'35'ff,
    MEDIUM_CHAMPAGNE                        = 0xF3'E5'AB'ff,
    MEDIUM_ORCHID                           = 0xBA'55'D3'ff,
    MEDIUM_PURPLE                           = 0x93'70'DB'ff,
    MEDIUM_SEA_GREEN                        = 0x3C'B3'71'ff,
    MEDIUM_SLATE_BLUE                       = 0x7B'68'EE'ff,
    MEDIUM_SPRING_GREEN                     = 0x00'FA'9A'ff,
    MEDIUM_TURQUOISE                        = 0x48'D1'CC'ff,
    MEDIUM_VIOLET_RED                       = 0xC7'15'85'ff,
    MELLOW_APRICOT                          = 0xF8'B8'78'ff,
    MELLOW_YELLOW                           = 0xF8'DE'7E'ff,
    MELON                                   = 0xFE'BA'AD'ff,
    METALLIC_GOLD                           = 0xD3'AF'37'ff,
    METALLIC_SEAWEED                        = 0x0A'7E'8C'ff,
    METALLIC_SUNBURST                       = 0x9C'7C'38'ff,
    MEXICAN_PINK                            = 0xE4'00'7C'ff,
    MIDDLE_BLUE                             = 0x7E'D4'E6'ff,
    MIDDLE_BLUE_GREEN                       = 0x8D'D9'CC'ff,
    MIDDLE_BLUE_PURPLE                      = 0x8B'72'BE'ff,
    MIDDLE_GREY                             = 0x8B'86'80'ff,
    MIDDLE_GREEN                            = 0x4D'8C'57'ff,
    MIDDLE_GREEN_YELLOW                     = 0xAC'BF'60'ff,
    MIDDLE_PURPLE                           = 0xD9'82'B5'ff,
    MIDDLE_RED                              = 0xE5'8E'73'ff,
    MIDDLE_RED_PURPLE                       = 0xA5'53'53'ff,
    MIDDLE_YELLOW                           = 0xFF'EB'00'ff,
    MIDDLE_YELLOW_RED                       = 0xEC'B1'76'ff,
    MIDNIGHT                                = 0x70'26'70'ff,
    MIDNIGHT_BLUE                           = 0x19'19'70'ff,
    MIDNIGHT_GREEN                          = 0x00'49'53'ff,
    EAGLE_GREEN                             = 0x00'49'53'ff,
    MIKADO_YELLOW                           = 0xFF'C4'0C'ff,
    MIMI_PINK                               = 0xFF'DA'E9'ff,
    MINDARO                                 = 0xE3'F9'88'ff,
    MING                                    = 0x36'74'7D'ff,
    MINION_YELLOW                           = 0xF5'E0'50'ff,
    MINT                                    = 0x3E'B4'89'ff,
    MINT_CREAM                              = 0xF5'FF'FA'ff,
    MINT_GREEN                              = 0x98'FF'98'ff,
    MISTY_MOSS                              = 0xBB'B4'77'ff,
    MISTY_ROSE                              = 0xFF'E4'E1'ff,
    MODE_BEIGE                              = 0x96'71'17'ff,
    MORNING_BLUE                            = 0x8D'A3'99'ff,
    MOSS_GREEN                              = 0x8A'9A'5B'ff,
    MOUNTAIN_MEADOW                         = 0x30'BA'8F'ff,
    MOUNTBATTEN_PINK                        = 0x99'7A'8D'ff,
    MSU_GREEN                               = 0x18'45'3B'ff,
    MULBERRY                                = 0xC5'4B'8C'ff,
    MULBERRY_CRAYOLA                        = 0xC8'50'9B'ff,
    MUSTARD                                 = 0xFF'DB'58'ff,
    MYRTLE_GREEN                            = 0x31'78'73'ff,
    MYSTIC                                  = 0xD6'52'82'ff,
    MYSTIC_MAROON                           = 0xAD'43'79'ff,
    NADESHIKO_PINK                          = 0xF6'AD'C6'ff,
    NAPLES_YELLOW                           = 0xFA'DA'5E'ff,
    NAVAJO_WHITE                            = 0xFF'DE'AD'ff,
    NAVY_BLUE                               = 0x00'00'80'ff,
    NAVY_BLUE_CRAYOLA                       = 0x19'74'D2'ff,
    NEON_BLUE                               = 0x46'66'FF'ff,
    NEON_CARROT                             = 0xFF'A3'43'ff,
    NEON_GREEN                              = 0x39'FF'14'ff,
    NEON_FUCHSIA                            = 0xFE'41'64'ff,
    NEW_YORK_PINK                           = 0xD7'83'7F'ff,
    NICKEL                                  = 0x72'74'72'ff,
    NON_PHOTO_BLUE                          = 0xA4'DD'ED'ff,
    NYANZA                                  = 0xE9'FF'DB'ff,
    OCEAN_BLUE                              = 0x4F'42'B5'ff,
    OCEAN_GREEN                             = 0x48'BF'91'ff,
    OCHRE                                   = 0xCC'77'22'ff,
    OLD_BURGUNDY                            = 0x43'30'2E'ff,
    OLD_GOLD                                = 0xCF'B5'3B'ff,
    OLD_LACE                                = 0xFD'F5'E6'ff,
    OLD_LAVENDER                            = 0x79'68'78'ff,
    OLD_MAUVE                               = 0x67'31'47'ff,
    OLD_ROSE                                = 0xC0'80'81'ff,
    OLD_SILVER                              = 0x84'84'82'ff,
    OLIVE                                   = 0x80'80'00'ff,
    OLIVE_DRAB_NUMBER_3                     = 0x6B'8E'23'ff,
    OD3                                     = 0x6B'8E'23'ff,
    OLIVE_DRAB_NUMBER_7                     = 0x3C'34'1F'ff,
    OD7                                     = 0x3C'34'1F'ff,
    OLIVE_GREEN                             = 0xB5'B3'5C'ff,
    OLIVINE                                 = 0x9A'B9'73'ff,
    ONYX                                    = 0x35'38'39'ff,
    OPAL                                    = 0xA8'C3'BC'ff,
    OPERA_MAUVE                             = 0xB7'84'A7'ff,
    ORANGE                                  = 0xFF'7F'00'ff,
    ORANGE_CRAYOLA                          = 0xFF'75'38'ff,
    ORANGE_PANTONE                          = 0xFF'58'00'ff,
    ORANGE_WEB                              = 0xFF'A5'00'ff,
    ORANGE_PEEL                             = 0xFF'9F'00'ff,
    ORANGE_RED                              = 0xFF'68'1F'ff,
    ORANGE_RED_CRAYOLA                      = 0xFF'53'49'ff,
    ORANGE_SODA                             = 0xFA'5B'3D'ff,
    ORANGE_YELLOW                           = 0xF5'BD'1F'ff,
    ORANGE_YELLOW_CRAYOLA                   = 0xF8'D5'68'ff,
    ORCHID                                  = 0xDA'70'D6'ff,
    ORCHID_PINK                             = 0xF2'BD'CD'ff,
    ORCHID_CRAYOLA                          = 0xE2'9C'D2'ff,
    OUTER_SPACE_CRAYOLA                     = 0x2D'38'3A'ff,
    OUTRAGEOUS_ORANGE                       = 0xFF'6E'4A'ff,
    OXBLOOD                                 = 0x4A'00'00'ff,
    OXFORD_BLUE                             = 0x00'21'47'ff,
    OU_CRIMSON_RED                          = 0x84'16'17'ff,
    PACIFIC_BLUE                            = 0x1C'A9'C9'ff,
    PAKISTAN_GREEN                          = 0x00'66'00'ff,
    PALATINATE_PURPLE                       = 0x68'28'60'ff,
    PALE_AQUA                               = 0xBC'D4'E6'ff,
    PALE_CERULEAN                           = 0x9B'C4'E2'ff,
    PALE_DOGWOOD                            = 0xED'7A'9B'ff,
    PALE_PINK                               = 0xFA'DA'DD'ff,
    PALE_PURPLE_PANTONE                     = 0xFA'E6'FA'ff,
    PALE_SILVER                             = 0xC9'C0'BB'ff,
    PALE_SPRING_BUD                         = 0xEC'EB'BD'ff,
    PANSY_PURPLE                            = 0x78'18'4A'ff,
    PAOLO_VERONESE_GREEN                    = 0x00'9B'7D'ff,
    PAPAYA_WHIP                             = 0xFF'EF'D5'ff,
    PARADISE_PINK                           = 0xE6'3E'62'ff,
    PARCHMENT                               = 0xF1'E9'D2'ff,
    PARIS_GREEN                             = 0x50'C8'78'ff,
    PASTEL_PINK                             = 0xDE'A5'A4'ff,
    PATRIARCH                               = 0x80'00'80'ff,
    PAYNES_GREY                             = 0x53'68'78'ff,
    PEACH                                   = 0xFF'E5'B4'ff,
    PEACH_CRAYOLA                           = 0xFF'CB'A4'ff,
    PEACH_PUFF                              = 0xFF'DA'B9'ff,
    PEAR                                    = 0xD1'E2'31'ff,
    PEARLY_PURPLE                           = 0xB7'68'A2'ff,
    PERIWINKLE                              = 0xCC'CC'FF'ff,
    PERIWINKLE_CRAYOLA                      = 0xC3'CD'E6'ff,
    PERMANENT_GERANIUM_LAKE                 = 0xE1'2C'2C'ff,
    PERSIAN_BLUE                            = 0x1C'39'BB'ff,
    PERSIAN_GREEN                           = 0x00'A6'93'ff,
    PERSIAN_INDIGO                          = 0x32'12'7A'ff,
    PERSIAN_ORANGE                          = 0xD9'90'58'ff,
    PERSIAN_PINK                            = 0xF7'7F'BE'ff,
    PERSIAN_PLUM                            = 0x70'1C'1C'ff,
    PERSIAN_RED                             = 0xCC'33'33'ff,
    PERSIAN_ROSE                            = 0xFE'28'A2'ff,
    PERSIMMON                               = 0xEC'58'00'ff,
    PEWTER_BLUE                             = 0x8B'A8'B7'ff,
    PHLOX                                   = 0xDF'00'FF'ff,
    PHTHALO_BLUE                            = 0x00'0F'89'ff,
    PHTHALO_GREEN                           = 0x12'35'24'ff,
    PICOTEE_BLUE                            = 0x2E'27'87'ff,
    PICTORIAL_CARMINE                       = 0xC3'0B'4E'ff,
    PIGGY_PINK                              = 0xFD'DD'E6'ff,
    PINE_GREEN                              = 0x01'79'6F'ff,
    PINE_TREE                               = 0x2A'2F'23'ff,
    PINK                                    = 0xFF'C0'CB'ff,
    PINK_PANTONE                            = 0xD7'48'94'ff,
    PINK_FLAMINGO                           = 0xFC'74'FD'ff,
    PINK_LACE                               = 0xFF'DD'F4'ff,
    PINK_LAVENDER                           = 0xD8'B2'D1'ff,
    PINK_SHERBET                            = 0xF7'8F'A7'ff,
    PISTACHIO                               = 0x93'C5'72'ff,
    PLATINUM                                = 0xE5'E4'E2'ff,
    PLUM                                    = 0x8E'45'85'ff,
    PLUM_WEB                                = 0xDD'A0'DD'ff,
    PLUMP_PURPLE                            = 0x59'46'B2'ff,
    POLISHED_PINE                           = 0x5D'A4'93'ff,
    POMP_AND_POWER                          = 0x86'60'8E'ff,
    POPSTAR                                 = 0xBE'4F'62'ff,
    PORTLAND_ORANGE                         = 0xFF'5A'36'ff,
    POWDER_BLUE                             = 0xB0'E0'E6'ff,
    PRINCETON_ORANGE                        = 0xF5'80'25'ff,
    PROCESS_YELLOW                          = 0xFF'EF'00'ff,
    PRUNE                                   = 0x70'1C'1C'ff,
    PRUSSIAN_BLUE                           = 0x00'31'53'ff,
    PSYCHEDELIC_PURPLE                      = 0xDF'00'FF'ff,
    PUCE                                    = 0xCC'88'99'ff,
    PULLMAN_BROWN                           = 0x64'41'17'ff,
    UPS_BROWN                               = 0x64'41'17'ff,
    PUMPKIN                                 = 0xFF'75'18'ff,
    PURPLE                                  = 0x6A'0D'AD'ff,
    PURPLE_WEB                              = 0x80'00'80'ff,
    PURPLE_MUNSELL                          = 0x9F'00'C5'ff,
    PURPLE_X11                              = 0xA0'20'F0'ff,
    PURPLE_MOUNTAIN_MAJESTY                 = 0x96'78'B6'ff,
    PURPLE_NAVY                             = 0x4E'51'80'ff,
    PURPLE_PIZZAZZ                          = 0xFE'4E'DA'ff,
    PURPLE_PLUM                             = 0x9C'51'B6'ff,
    PURPUREUS                               = 0x9A'4E'AE'ff,
    QUEEN_BLUE                              = 0x43'6B'95'ff,
    QUEEN_PINK                              = 0xE8'CC'D7'ff,
    QUICK_SILVER                            = 0xA6'A6'A6'ff,
    QUINACRIDONE_MAGENTA                    = 0x8E'3A'59'ff,
    RADICAL_RED                             = 0xFF'35'5E'ff,
    RAISIN_BLACK                            = 0x24'21'24'ff,
    RAJAH                                   = 0xFB'AB'60'ff,
    RASPBERRY                               = 0xE3'0B'5D'ff,
    RASPBERRY_GLACE                         = 0x91'5F'6D'ff,
    RASPBERRY_ROSE                          = 0xB3'44'6C'ff,
    RAW_SIENNA                              = 0xD6'8A'59'ff,
    RAW_UMBER                               = 0x82'66'44'ff,
    RAZZLE_DAZZLE_ROSE                      = 0xFF'33'CC'ff,
    RAZZMATAZZ                              = 0xE3'25'6B'ff,
    RAZZMIC_BERRY                           = 0x8D'4E'85'ff,
    REBECCA_PURPLE                          = 0x66'33'99'ff,
    RED                                     = 0xFF'00'00'ff,
    RED_CRAYOLA                             = 0xEE'20'4D'ff,
    RED_MUNSELL                             = 0xF2'00'3C'ff,
    RED_NCS                                 = 0xC4'02'33'ff,
    RED_PANTONE                             = 0xED'29'39'ff,
    RED_PIGMENT                             = 0xED'1C'24'ff,
    RED_RYB                                 = 0xFE'27'12'ff,
    RED_ORANGE                              = 0xFF'53'49'ff,
    RED_ORANGE_CRAYOLA                      = 0xFF'68'1F'ff,
    RED_ORANGE_COLOR_WHEEL                  = 0xFF'45'00'ff,
    RED_PURPLE                              = 0xE4'00'78'ff,
    RED_SALSA                               = 0xFD'3A'4A'ff,
    RED_VIOLET                              = 0xC7'15'85'ff,
    RED_VIOLET_CRAYOLA                      = 0xC0'44'8F'ff,
    RED_VIOLET_COLOR_WHEEL                  = 0x92'2B'3E'ff,
    REDWOOD                                 = 0xA4'5A'52'ff,
    RESOLUTION_BLUE                         = 0x00'23'87'ff,
    RHYTHM                                  = 0x77'76'96'ff,
    RICH_BLACK                              = 0x00'40'40'ff,
    RICH_BLACK_FOGRA29                      = 0x01'0B'13'ff,
    RICH_BLACK_FOGRA39                      = 0x01'02'03'ff,
    RIFLE_GREEN                             = 0x44'4C'38'ff,
    ROBIN_EGG_BLUE                          = 0x00'CC'CC'ff,
    ROCKET_METALLIC                         = 0x8A'7F'80'ff,
    ROJO_SPANISH_RED                        = 0xA9'11'01'ff,
    ROMAN_SILVER                            = 0x83'89'96'ff,
    ROSE                                    = 0xFF'00'7F'ff,
    ROSE_BONBON                             = 0xF9'42'9E'ff,
    ROSE_DUST                               = 0x9E'5E'6F'ff,
    ROSE_EBONY                              = 0x67'48'46'ff,
    ROSE_MADDER                             = 0xE3'26'36'ff,
    ROSE_PINK                               = 0xFF'66'CC'ff,
    ROSE_POMPADOUR                          = 0xED'7A'9B'ff,
    ROSE_QUARTZ                             = 0xAA'98'A9'ff,
    ROSE_RED                                = 0xC2'1E'56'ff,
    ROSE_TAUPE                              = 0x90'5D'5D'ff,
    ROSE_VALE                               = 0xAB'4E'52'ff,
    ROSEWOOD                                = 0x65'00'0B'ff,
    ROSSO_CORSA                             = 0xD4'00'00'ff,
    ROSY_BROWN                              = 0xBC'8F'8F'ff,
    ROYAL_BLUE_DARK                         = 0x00'23'66'ff,
    ROYAL_BLUE_LIGHT                        = 0x41'69'E1'ff,
    ROYAL_PURPLE                            = 0x78'51'A9'ff,
    ROYAL_YELLOW                            = 0xFA'DA'5E'ff,
    RUBER                                   = 0xCE'46'76'ff,
    RUBINE_RED                              = 0xD1'00'56'ff,
    RUBY                                    = 0xE0'11'5F'ff,
    RUBY_RED                                = 0x9B'11'1E'ff,
    RUFOUS                                  = 0xA8'1C'07'ff,
    RUSSET                                  = 0x80'46'1B'ff,
    RUSSIAN_GREEN                           = 0x67'92'67'ff,
    RUSSIAN_VIOLET                          = 0x32'17'4D'ff,
    RUST                                    = 0xB7'41'0E'ff,
    RUSTY_RED                               = 0xDA'2C'43'ff,
    SACRAMENTO_STATE_GREEN                  = 0x04'39'27'ff,
    SADDLE_BROWN                            = 0x8B'45'13'ff,
    SAFETY_ORANGE_1                         = 0xFF'78'00'ff,
    SAFETY_ORANGE_2                         = 0xFF'67'00'ff,
    BLAZE_ORANGE                            = 0xFF'67'00'ff,
    SAFETY_YELLOW                           = 0xEE'D2'02'ff,
    SAFFRON                                 = 0xF4'C4'30'ff,
    SAGE                                    = 0xBC'B8'8A'ff,
    ST_PATRICKS_BLUE                        = 0x23'29'7A'ff,
    SALMON                                  = 0xFA'80'72'ff,
    SALMON_PINK                             = 0xFF'91'A4'ff,
    SAND                                    = 0xC2'B2'80'ff,
    SAND_DUNE                               = 0x96'71'17'ff,
    SANDY_BROWN                             = 0xF4'A4'60'ff,
    SAP_GREEN                               = 0x50'7D'2A'ff,
    SAPPHIRE                                = 0x0F'52'BA'ff,
    SAPPHIRE_BLUE                           = 0x00'67'A5'ff,
    SAPPHIRE_CRAYOLA                        = 0x00'67'A5'ff,
    SATIN_SHEEN_GOLD                        = 0xCB'A1'35'ff,
    SCARLET                                 = 0xFF'24'00'ff,
    SCHAUSS_PINK                            = 0xFF'91'AF'ff,
    SCHOOL_BUS_YELLOW                       = 0xFF'D8'00'ff,
    SCREAMIN_GREEN                          = 0x66'FF'66'ff,
    SEA_GREEN                               = 0x2E'8B'57'ff,
    SEA_GREEN_CRAYOLA                       = 0x00'FF'CD'ff,
    SEAL_BROWN                              = 0x59'26'0B'ff,
    SEASHELL                                = 0xFF'F5'EE'ff,
    SELECTIVE_YELLOW                        = 0xFF'BA'00'ff,
    SEPIA                                   = 0x70'42'14'ff,
    SHADOW                                  = 0x8A'79'5D'ff,
    SHADOW_BLUE                             = 0x77'8B'A5'ff,
    SHAMROCK_GREEN                          = 0x00'9E'60'ff,
    SHEEN_GREEN                             = 0x8F'D4'00'ff,
    SHIMMERING_BLUSH                        = 0xD9'86'95'ff,
    SHINY_SHAMROCK                          = 0x5F'A7'78'ff,
    SHOCKING_PINK                           = 0xFC'0F'C0'ff,
    SHOCKING_PINK_CRAYOLA                   = 0xFF'6F'FF'ff,
    SIENNA                                  = 0x88'2D'17'ff,
    SILVER                                  = 0xC0'C0'C0'ff,
    SILVER_CRAYOLA                          = 0xC9'C0'BB'ff,
    SILVER_METALLIC                         = 0xAA'A9'AD'ff,
    SILVER_CHALICE                          = 0xAC'AC'AC'ff,
    SILVER_PINK                             = 0xC4'AE'AD'ff,
    SILVER_SAND                             = 0xBF'C1'C2'ff,
    SINOPIA                                 = 0xCB'41'0B'ff,
    SIZZLING_RED                            = 0xFF'38'55'ff,
    SIZZLING_SUNRISE                        = 0xFF'DB'00'ff,
    SKOBELOFF                               = 0x00'74'74'ff,
    SKY_BLUE                                = 0x87'CE'EB'ff,
    SKY_BLUE_CRAYOLA                        = 0x76'D7'EA'ff,
    SKY_MAGENTA                             = 0xCF'71'AF'ff,
    SLATE_BLUE                              = 0x6A'5A'CD'ff,
    SLATE_GRAY                              = 0x70'80'90'ff,
    SLIMY_GREEN                             = 0x29'96'17'ff,
    SMITTEN                                 = 0xC8'41'86'ff,
    SMOKY_BLACK                             = 0x10'0C'08'ff,
    SNOW                                    = 0xFF'FA'FA'ff,
    SOLID_PINK                              = 0x89'38'43'ff,
    SONIC_SILVER                            = 0x75'75'75'ff,
    SPACE_CADET                             = 0x1D'29'51'ff,
    SPANISH_BISTRE                          = 0x80'75'32'ff,
    SPANISH_BLUE                            = 0x00'70'B8'ff,
    SPANISH_CARMINE                         = 0xD1'00'47'ff,
    SPANISH_GRAY                            = 0x98'98'98'ff,
    SPANISH_GREEN                           = 0x00'91'50'ff,
    SPANISH_ORANGE                          = 0xE8'61'00'ff,
    SPANISH_PINK                            = 0xF7'BF'BE'ff,
    SPANISH_RED                             = 0xE6'00'26'ff,
    SPANISH_SKY_BLUE                        = 0x00'FF'FF'ff,
    SPANISH_VIOLET                          = 0x4C'28'82'ff,
    SPANISH_VIRIDIAN                        = 0x00'7F'5C'ff,
    SPRING_BUD                              = 0xA7'FC'00'ff,
    SPRING_FROST                            = 0x87'FF'2A'ff,
    SPRING_GREEN                            = 0x00'FF'7F'ff,
    SPRING_GREEN_CRAYOLA                    = 0xEC'EB'BD'ff,
    STAR_COMMAND_BLUE                       = 0x00'7B'B8'ff,
    STEEL_BLUE                              = 0x46'82'B4'ff,
    STEEL_PINK                              = 0xCC'33'CC'ff,
    STEEL_TEAL                              = 0x5F'8A'8B'ff,
    STIL_DE_GRAIN_YELLOW                    = 0xFA'DA'5E'ff,
    STRAW                                   = 0xE4'D9'6F'ff,
    STRAWBERRY                              = 0xFA'50'53'ff,
    STRAWBERRY_BLONDE                       = 0xFF'93'61'ff,
    SUGAR_PLUM                              = 0x91'4E'75'ff,
    SUNGLOW                                 = 0xFF'CC'33'ff,
    SUNRAY                                  = 0xE3'AB'57'ff,
    SUNSET                                  = 0xFA'D6'A5'ff,
    SUPER_PINK                              = 0xCF'6B'A9'ff,
    SWEET_BROWN                             = 0xA8'37'31'ff,
    SYRACUSE_ORANGE                         = 0xD4'45'00'ff,
    TAN                                     = 0xD2'B4'8C'ff,
    TAN_CRAYOLA                             = 0xD9'9A'6C'ff,
    TANGERINE                               = 0xF2'85'00'ff,
    TANGO_PINK                              = 0xE4'71'7A'ff,
    TART_ORANGE                             = 0xFB'4D'46'ff,
    TAUPE                                   = 0x48'3C'32'ff,
    TAUPE_GRAY                              = 0x8B'85'89'ff,
    TEA_GREEN                               = 0xD0'F0'C0'ff,
    TEA_ROSE_1                              = 0xF8'83'79'ff,
    TEA_ROSE_2                              = 0xF4'C2'C2'ff,
    TEAL                                    = 0x00'80'80'ff,
    TEAL_BLUE                               = 0x36'75'88'ff,
    TELEMAGENTA                             = 0xCF'34'76'ff,
    TENNÉ_TAWNY                             = 0xCD'57'00'ff,
    TENNE_TAWNY                             = 0xCD'57'00'ff,
    TERRA_COTTA                             = 0xE2'72'5B'ff,
    THISTLE                                 = 0xD8'BF'D8'ff,
    THULIAN_PINK                            = 0xDE'6F'A1'ff,
    TICKLE_ME_PINK                          = 0xFC'89'AC'ff,
    TIFFANY_BLUE                            = 0x0A'BA'B5'ff,
    TIMBERWOLF                              = 0xDB'D7'D2'ff,
    TITANIUM_YELLOW                         = 0xEE'E6'00'ff,
    TOMATO                                  = 0xFF'63'47'ff,
    TROPICAL_RAINFOREST                     = 0x00'75'5E'ff,
    TRUE_BLUE                               = 0x2D'68'C4'ff,
    TRYPAN_BLUE                             = 0x1C'05'B3'ff,
    TUFTS_BLUE                              = 0x3E'8E'DE'ff,
    TUMBLEWEED                              = 0xDE'AA'88'ff,
    TURQUOISE                               = 0x40'E0'D0'ff,
    TURQUOISE_BLUE                          = 0x00'FF'EF'ff,
    TURQUOISE_GREEN                         = 0xA0'D6'B4'ff,
    TURTLE_GREEN                            = 0x8A'9A'5B'ff,
    TUSCAN                                  = 0xFA'D6'A5'ff,
    TUSCAN_BROWN                            = 0x6F'4E'37'ff,
    TUSCAN_RED                              = 0x7C'48'48'ff,
    TUSCAN_TAN                              = 0xA6'7B'5B'ff,
    TUSCANY                                 = 0xC0'99'99'ff,
    TWILIGHT_LAVENDER                       = 0x8A'49'6B'ff,
    TYRIAN_PURPLE                           = 0x66'02'3C'ff,
    UA_BLUE                                 = 0x00'33'AA'ff,
    UA_RED                                  = 0xD9'00'4C'ff,
    ULTRAMARINE                             = 0x3F'00'FF'ff,
    ULTRAMARINE_BLUE                        = 0x41'66'F5'ff,
    ULTRA_PINK                              = 0xFF'6F'FF'ff,
    ULTRA_RED                               = 0xFC'6C'85'ff,
    UMBER                                   = 0x63'51'47'ff,
    UNBLEACHED_SILK                         = 0xFF'DD'CA'ff,
    UNITED_NATIONS_BLUE                     = 0x5B'92'E5'ff,
    UNIVERSITY_OF_PENNSYLVANIA_RED          = 0xA5'00'21'ff,
    UNMELLOW_YELLOW                         = 0xFF'FF'66'ff,
    UP_FOREST_GREEN                         = 0x01'44'21'ff,
    UP_MAROON                               = 0x7B'11'13'ff,
    UPSDELL_RED                             = 0xAE'20'29'ff,
    URANIAN_BLUE                            = 0xAF'DB'F5'ff,
    USAFA_BLUE                              = 0x00'4F'98'ff,
    UNITED_STATES_AIRFORCE_ACADEMY_BLUE     = 0x00'4F'98'ff,
    VAN_DYKE_BROWN                          = 0x66'42'28'ff,
    VANILLA                                 = 0xF3'E5'AB'ff,
    VANILLA_ICE                             = 0xF3'8F'A9'ff, // Ice, ice, baby.
    VEGAS_GOLD                              = 0xC5'B3'58'ff,
    VENETIAN_RED                            = 0xC8'08'15'ff,
    VERDIGRIS                               = 0x43'B3'AE'ff,
    VERMILION_1                             = 0xE3'42'34'ff,
    VERMILION_2                             = 0xD9'38'1E'ff,
    VERONICA                                = 0xA0'20'F0'ff,
    VIOLET                                  = 0x8F'00'FF'ff,
    VIOLET_COLOR_WHEEL                      = 0x7F'00'FF'ff,
    VIOLET_CRAYOLA                          = 0x96'3D'7F'ff,
    VIOLET_RYB                              = 0x86'01'AF'ff,
    VIOLET_WEB                              = 0xEE'82'EE'ff,
    VIOLET_BLUE                             = 0x32'4A'B2'ff,
    VIOLET_BLUE_CRAYOLA                     = 0x76'6E'C8'ff,
    VIOLET_RED                              = 0xF7'53'94'ff,
    VIRIDIAN                                = 0x40'82'6D'ff,
    VIRIDIAN_GREEN                          = 0x00'96'98'ff,
    VIVID_BURGUNDY                          = 0x9F'1D'35'ff,
    VIVID_SKY_BLUE                          = 0x00'CC'FF'ff,
    VIVID_TANGERINE                         = 0xFF'A0'89'ff,
    VIVID_VIOLET                            = 0x9F'00'FF'ff,
    VOLT                                    = 0xCE'FF'00'ff,
    WARM_BLACK                              = 0x00'42'42'ff,
    WHEAT                                   = 0xF5'DE'B3'ff,
    WHITE                                   = 0xFF'FF'FF'ff,
    WILD_BLUE_YONDER                        = 0xA2'AD'D0'ff,
    WILD_ORCHID                             = 0xD4'70'A2'ff,
    WILD_STRAWBERRY                         = 0xFF'43'A4'ff,
    WILD_WATERMELON                         = 0xFC'6C'85'ff,
    WINDSOR_TAN                             = 0xA7'55'02'ff,
    WINE                                    = 0x72'2F'37'ff,
    WINE_DREGS                              = 0x67'31'47'ff,
    WINTER_SKY                              = 0xFF'00'7C'ff,
    WINTERGREEN_DREAM                       = 0x56'88'7D'ff,
    WISTERIA                                = 0xC9'A0'DC'ff,
    WOOD_BROWN                              = 0xC1'9A'6B'ff,
    XANADU                                  = 0x73'86'78'ff,
    XANTHIC                                 = 0xEE'ED'09'ff,
    XANTHOUS                                = 0xF1'B4'2F'ff,
    YALE_BLUE                               = 0x00'35'6B'ff,
    YELLOW                                  = 0xFF'FF'00'ff,
    YELLOW_CRAYOLA                          = 0xFC'E8'83'ff,
    YELLOW_MUNSELL                          = 0xEF'CC'00'ff,
    YELLOW_NCS                              = 0xFF'D3'00'ff,
    YELLOW_PANTONE                          = 0xFE'DF'00'ff,
    YELLOW_PROCESS                          = 0xFF'EF'00'ff,
    YELLOW_RYB                              = 0xFE'FE'33'ff,
    YELLOW_GREEN                            = 0x9A'CD'32'ff,
    YELLOW_GREEN_CRAYOLA                    = 0xC5'E3'84'ff,
    YELLOW_GREEN_COLOR_WHEEL                = 0x30'B2'1A'ff,
    YELLOW_ORANGE                           = 0xFF'AE'42'ff,
    YELLOW_ORANGE_COLOR_WHEEL               = 0xFF'95'05'ff,
    YELLOW_SUNSHINE                         = 0xFF'F7'00'ff,
    YINMN_BLUE                              = 0x2E'50'90'ff,
    ZAFFRE                                  = 0x00'14'A8'ff,
    ZOMP                                    = 0x39'A7'8E'ff,

    PANTONE_448_C                           = 0x4A'41'2A'ff
};
#else
namespace hex_color
{
    constexpr uint32_t        ABSOLUTE_ZERO{                           0x00'48'BA'ff };
    constexpr uint32_t        ACID_GREEN{                              0xB0'BF'1A'ff };
    constexpr uint32_t        AERO{                                    0x7C'B9'E8'ff };
    constexpr uint32_t        AERO_BLUE{                               0xC0'E8'D5'ff };
    constexpr uint32_t        AFRICAN_VIOLET{                          0xB2'84'BE'ff };
    constexpr uint32_t        AIR_SUPERIORITY_BLUE{                    0x72'A0'C1'ff };
    constexpr uint32_t        ALABASTER{                               0xED'EA'E0'ff };
    constexpr uint32_t        ALICE_BLUE{                              0xF0'F8'FF'ff };
    constexpr uint32_t        ALLOY_ORANGE{                            0xC4'62'10'ff };
    constexpr uint32_t        ALMOND{                                  0xEF'DE'CD'ff };
    constexpr uint32_t        AMARANTH{                                0xE5'2B'50'ff };
    constexpr uint32_t        AMARANTH_M_AND_P{                        0x9F'2B'68'ff };
    constexpr uint32_t        AMARANTH_PINK{                           0xF1'9C'BB'ff };
    constexpr uint32_t        AMARANTH_PURPLE{                         0xAB'27'4F'ff };
    constexpr uint32_t        AMARANTH_RED{                            0xD3'21'2D'ff };
    constexpr uint32_t        AMAZON{                                  0x3B'7A'57'ff };
    constexpr uint32_t        AMBER{                                   0xFF'BF'00'ff };
    constexpr uint32_t        AMBER_SAE{                               0xFF'7E'00'ff };
    constexpr uint32_t        AMBER_ECE{                               AMBER_SAE };
    constexpr uint32_t        AMETHYST{                                0x99'66'CC'ff };
    constexpr uint32_t        ANDROID_GREEN{                           0x3D'DC'84'ff };
    constexpr uint32_t        ANTIQUE_BRASS{                           0xCD'95'75'ff };
    constexpr uint32_t        ANTIQUE_BRONZE{                          0x66'5D'1E'ff };
    constexpr uint32_t        ANTIQUE_FUCHSIA{                         0x91'5C'83'ff };
    constexpr uint32_t        ANTIQUE_RUBY{                            0x84'1B'2D'ff };
    constexpr uint32_t        ANTIQUE_WHITE{                           0xFA'EB'D7'ff };
    constexpr uint32_t        AO{                                      0x00'80'00'ff };
    constexpr uint32_t        APPLE_GREEN{                             0x8D'B6'00'ff };
    constexpr uint32_t        APRICOT{                                 0xFB'CE'B1'ff };
    constexpr uint32_t        AQUA{                                    0x00'FF'FF'ff };
    constexpr uint32_t        AQUAMARINE{                              0x7F'FF'D4'ff };
    constexpr uint32_t        ARCTIC_LIME{                             0xD0'FF'14'ff };
    constexpr uint32_t        ARMY_GREEN{                              0x4B'53'20'ff };
    constexpr uint32_t        ARTICHOKE{                               0x8F'97'79'ff };
    constexpr uint32_t        ARYLIDE_YELLOW{                          0xE9'D6'6B'ff };
    constexpr uint32_t        ASH_GRAY{                                0xB2'BE'B5'ff };
    constexpr uint32_t        ASPARAGUS{                               0x87'A9'6B'ff };
    constexpr uint32_t        ATOMIC_TANGERINE{                        0xFF'99'66'ff };
    constexpr uint32_t        AUBURN{                                  0xA5'2A'2A'ff };
    constexpr uint32_t        AUREOLIN{                                0xFD'EE'00'ff };
    constexpr uint32_t        AVOCADO{                                 0x56'82'03'ff };
    constexpr uint32_t        AZURE{                                   0x00'7F'FF'ff };
    constexpr uint32_t        AZURE_X11{                               0xF0'FF'FF'ff };
    constexpr uint32_t        AZURE_WEB{                               AZURE_X11 };
    constexpr uint32_t        BABY_BLUE{                               0x89'CF'F0'ff };
    constexpr uint32_t        BABY_BLUE_EYES{                          0xA1'CA'F1'ff };
    constexpr uint32_t        BABY_PINK{                               0xF4'C2'C2'ff };
    constexpr uint32_t        BABY_POWDER{                             0xFE'FE'FA'ff };
    constexpr uint32_t        BAKER_MILLER_PINK{                       0xFF'91'AF'ff };
    constexpr uint32_t        BANANA_MANIA{                            0xFA'E7'B5'ff };
    constexpr uint32_t        BARBIE_PINK{                             0xDA'18'84'ff };
    constexpr uint32_t        BARN_RED{                                0x7C'0A'02'ff };
    constexpr uint32_t        BATTLESHIP_GREY{                         0x84'84'82'ff };
    constexpr uint32_t        BEAU_BLUE{                               0xBC'D4'E6'ff };
    constexpr uint32_t        BEAVER{                                  0x9F'81'70'ff };
    constexpr uint32_t        BEIGE{                                   0xF5'F5'DC'ff };
    constexpr uint32_t        B_DAZZLED_BLUE{                          0x2E'58'94'ff };
    constexpr uint32_t        BIG_DIP_O_RUBY{                          0x9C'25'42'ff };
    constexpr uint32_t        BISQUE{                                  0xFF'E4'C4'ff };
    constexpr uint32_t        BISTRE{                                  0x3D'2B'1F'ff };
    constexpr uint32_t        BISTRE_BROWN{                            0x96'71'17'ff };
    constexpr uint32_t        BITTER_LEMON{                            0xCA'E0'0D'ff };
    constexpr uint32_t        BITTER_LIME{                             0xBF'FF'00'ff };
    constexpr uint32_t        BITTERSWEET{                             0xFE'6F'5E'ff };
    constexpr uint32_t        BITTERSWEET_SHIMMER{                     0xBF'4F'51'ff };
    constexpr uint32_t        BLACK{                                   0x00'00'00'ff };
    constexpr uint32_t        BLACK_BEAN{                              0x3D'0C'02'ff };
    constexpr uint32_t        BLACK_CHOCOLATE{                         0x1B'18'11'ff };
    constexpr uint32_t        BLACK_COFFEE{                            0x3B'2F'2F'ff };
    constexpr uint32_t        BLACK_CORAL{                             0x54'62'6F'ff };
    constexpr uint32_t        BLACK_OLIVE{                             0x3B'3C'36'ff };
    constexpr uint32_t        BLACK_SHADOWS{                           0xBF'AF'B2'ff };
    constexpr uint32_t        BLANCHED_ALMOND{                         0xFF'EB'CD'ff };
    constexpr uint32_t        BLAST_OFF_BRONZE{                        0xA5'71'64'ff };
    constexpr uint32_t        BLEU_DE_FRANCE{                          0x31'8C'E7'ff };
    constexpr uint32_t        BLIZZARD_BLUE{                           0xAC'E5'EE'ff };
    constexpr uint32_t        BLOND{                                   0xFA'F0'BE'ff };
    constexpr uint32_t        BLOOD_RED{                               0x66'00'00'ff };
    constexpr uint32_t        BLUE{                                    0x00'00'FF'ff };
    constexpr uint32_t        BLUE_CRAYOLA{                            0x1F'75'FE'ff };
    constexpr uint32_t        BLUE_MUNSELL{                            0x00'93'AF'ff };
    constexpr uint32_t        BLUE_NCS{                                0x00'87'BD'ff };
    constexpr uint32_t        BLUE_PANTONE{                            0x00'18'A8'ff };
    constexpr uint32_t        BLUE_PIGMENT{                            0x33'33'99'ff };
    constexpr uint32_t        BLUE_RYB{                                0x02'47'FE'ff };
    constexpr uint32_t        BLUE_BELL{                               0xA2'A2'D0'ff };
    constexpr uint32_t        BLUE_GRAY{                               0x66'99'CC'ff };
    constexpr uint32_t        BLUE_GREEN{                              0x0D'98'BA'ff };
    constexpr uint32_t        BLUE_GREEN_COLOR_WHEEL{                  0x06'4E'40'ff };
    constexpr uint32_t        BLUE_JEANS{                              0x5D'AD'EC'ff };
    constexpr uint32_t        BLUE_SAPPHIRE{                           0x12'61'80'ff };
    constexpr uint32_t        BLUE_VIOLET{                             0x8A'2B'E2'ff };
    constexpr uint32_t        BLUE_VIOLET_CRAYOLA{                     0x73'66'BD'ff };
    constexpr uint32_t        BLUE_VIOLET_COLOR_WHEEL{                 0x4D'1A'7F'ff };
    constexpr uint32_t        BLUE_YONDER{                             0x50'72'A7'ff };
    constexpr uint32_t        BLUETIFUL{                               0x3C'69'E7'ff };
    constexpr uint32_t        BLUSH{                                   0xDE'5D'83'ff };
    constexpr uint32_t        BOLE{                                    0x79'44'3B'ff };
    constexpr uint32_t        BONE{                                    0xE3'DA'C9'ff };
    constexpr uint32_t        BOTTLE_GREEN{                            0x00'6A'4E'ff };
    constexpr uint32_t        BRANDY{                                  0x87'41'3F'ff };
    constexpr uint32_t        BRICK_RED{                               0xCB'41'54'ff };
    constexpr uint32_t        BRIGHT_GREEN{                            0x66'FF'00'ff };
    constexpr uint32_t        BRIGHT_LILAC{                            0xD8'91'EF'ff };
    constexpr uint32_t        BRIGHT_MAROON{                           0xC3'21'48'ff };
    constexpr uint32_t        BRIGHT_NAVY_BLUE{                        0x19'74'D2'ff };
    constexpr uint32_t        BRIGHT_YELLOW_CRAYOLA{                   0xFF'AA'1D'ff };
    constexpr uint32_t        BRILLIANT_ROSE{                          0xFF'55'A3'ff };
    constexpr uint32_t        BRINK_PINK{                              0xFB'60'7F'ff };
    constexpr uint32_t        BRITISH_RACING_GREEN{                    0x00'42'25'ff };
    constexpr uint32_t        BRONZE{                                  0xCD'7F'32'ff };
    constexpr uint32_t        BROWN{                                   0x88'54'0B'ff };
    constexpr uint32_t        BROWN_SUGAR{                             0xAF'6E'4D'ff };
    constexpr uint32_t        BRUNSWICK_GREEN{                         0x1B'4D'3E'ff };
    constexpr uint32_t        BUD_GREEN{                               0x7B'B6'61'ff };
    constexpr uint32_t        BUFF{                                    0xFF'C6'80'ff };
    constexpr uint32_t        BURGUNDY{                                0x80'00'20'ff };
    constexpr uint32_t        BURLYWOOD{                               0xDE'B8'87'ff };
    constexpr uint32_t        BURNISHED_BROWN{                         0xA1'7A'74'ff };
    constexpr uint32_t        BURNT_ORANGE{                            0xCC'55'00'ff };
    constexpr uint32_t        BURNT_SIENNA{                            0xE9'74'51'ff };
    constexpr uint32_t        BURNT_UMBER{                             0x8A'33'24'ff };
    constexpr uint32_t        BYZANTINE{                               0xBD'33'A4'ff };
    constexpr uint32_t        BYZANTIUM{                               0x70'29'63'ff };
    constexpr uint32_t        CADET{                                   0x53'68'72'ff };
    constexpr uint32_t        CADET_BLUE{                              0x5F'9E'A0'ff };
    constexpr uint32_t        CADET_BLUE_CRAYOLA{                      0xA9'B2'C3'ff };
    constexpr uint32_t        CADET_GREY{                              0x91'A3'B0'ff };
    constexpr uint32_t        CADMIUM_GREEN{                           0x00'6B'3C'ff };
    constexpr uint32_t        CADMIUM_ORANGE{                          0xED'87'2D'ff };
    constexpr uint32_t        CADMIUM_RED{                             0xE3'00'22'ff };
    constexpr uint32_t        CADMIUM_YELLOW{                          0xFF'F6'00'ff };
    constexpr uint32_t        CAFÉ_AU_LAIT{                            0xA6'7B'5B'ff };
    constexpr uint32_t        CAFE_AU_LAIT{                            CAFÉ_AU_LAIT };
    constexpr uint32_t        CAFÉ_NOIR{                               0x4B'36'21'Ff };
    constexpr uint32_t        CAFE_NOIR{                               CAFÉ_NOIR };
    constexpr uint32_t        CAMBRIDGE_BLUE{                          0xA3'C1'AD'ff };
    constexpr uint32_t        CAMEL{                                   0xC1'9A'6B'ff };
    constexpr uint32_t        CAMEO_PINK{                              0xEF'BB'CC'ff };
    constexpr uint32_t        CANARY{                                  0xFF'FF'99'ff };
    constexpr uint32_t        CANARY_YELLOW{                           0xFF'EF'00'ff };
    constexpr uint32_t        CANDY_APPLE_RED{                         0xFF'08'00'ff };
    constexpr uint32_t        CANDY_PINK{                              0xE4'71'7A'ff };
    constexpr uint32_t        CAPRI{                                   0x00'BF'FF'ff };
    constexpr uint32_t        CAPUT_MORTUUM{                           0x59'27'20'ff };
    constexpr uint32_t        CARDINAL{                                0xC4'1E'3A'ff };
    constexpr uint32_t        CARIBBEAN_GREEN{                         0x00'CC'99'ff };
    constexpr uint32_t        CARMINE{                                 0x96'00'18'ff };
    constexpr uint32_t        CARMINE_M_AND_P{                         0xD7'00'40'ff };
    constexpr uint32_t        CARNATION_PINK{                          0xFF'A6'C9'ff };
    constexpr uint32_t        CARNELIAN{                               0xB3'1B'1B'ff };
    constexpr uint32_t        CAROLINA_BLUE{                           0x56'A0'D3'ff };
    constexpr uint32_t        CARROT_ORANGE{                           0xED'91'21'ff };
    constexpr uint32_t        CASTLETON_GREEN{                         0x00'56'3F'ff };
    constexpr uint32_t        CATAWBA{                                 0x70'36'42'ff };
    constexpr uint32_t        CEDAR_CHEST{                             0xC9'5A'49'ff };
    constexpr uint32_t        CELADON{                                 0xAC'E1'AF'ff };
    constexpr uint32_t        CELADON_BLUE{                            0x00'7B'A7'ff };
    constexpr uint32_t        CELADON_GREEN{                           0x2F'84'7C'ff };
    constexpr uint32_t        CELESTE{                                 0xB2'FF'FF'ff };
    constexpr uint32_t        CELTIC_BLUE{                             0x24'6B'CE'ff };
    constexpr uint32_t        CERISE{                                  0xDE'31'63'ff };
    constexpr uint32_t        CERULEAN{                                0x00'7B'A7'ff };
    constexpr uint32_t        CERULEAN_BLUE{                           0x2A'52'BE'ff };
    constexpr uint32_t        CERULEAN_FROST{                          0x6D'9B'C3'ff };
    constexpr uint32_t        CERULEAN_CRAYOLA{                        0x1D'AC'D6'ff };
    constexpr uint32_t        CG_BLUE{                                 0x00'7A'A5'ff };
    constexpr uint32_t        CG_RED{                                  0xE0'3C'31'ff };
    constexpr uint32_t        CHAMPAGN{                                0xF7'E7'CE'ff };
    constexpr uint32_t        CHAMPAGNE_PINK{                          0xF1'DD'CF'ff };
    constexpr uint32_t        CHARCOAL{                                0x36'45'4F'ff };
    constexpr uint32_t        CHARLESTON_GREEN{                        0x23'2B'2B'ff };
    constexpr uint32_t        CHARM_PINK{                              0xE6'8F'AC'ff };
    constexpr uint32_t        CHARTREUSE_TRADITIONAL{                  0xDF'FF'00'ff };
    constexpr uint32_t        CHARTREUSE_WEB{                          0x7F'FF'00'ff };
    constexpr uint32_t        CHERRY_BLOSSOM_PINK{                     0xFF'B7'C5'ff };
    constexpr uint32_t        CHESTNUT{                                0x95'45'35'ff };
    constexpr uint32_t        CHILI_RED{                               0xE2'3D'28'ff };
    constexpr uint32_t        CHINA_PINK{                              0xDE'6F'A1'ff };
    constexpr uint32_t        CHINA_ROSE{                              0xA8'51'6E'ff };
    constexpr uint32_t        CHINESE_RED{                             0xAA'38'1E'ff };
    constexpr uint32_t        CHINESE_VIOLET{                          0x85'60'88'ff };
    constexpr uint32_t        CHINESE_YELLOW{                          0xFF'B2'00'ff };
    constexpr uint32_t        CHOCOLATE_TRADITIONAL{                   0x7B'3F'00'ff };
    constexpr uint32_t        CHOCOLATE_WEB{                           0xD2'69'1E'ff };
    constexpr uint32_t        CHOCOLATE_COSMOS{                        0x58'11'1A'ff };
    constexpr uint32_t        CHROME_YELLOW{                           0xFF'A7'00'ff };
    constexpr uint32_t        CINEREOUS{                               0x98'81'7B'ff };
    constexpr uint32_t        CINNABAR{                                0xE3'42'34'ff };
    constexpr uint32_t        CINNAMON_SATIN{                          0xCD'60'7E'ff };
    constexpr uint32_t        CITRINE{                                 0xE4'D0'0A'ff };
    constexpr uint32_t        CITRON{                                  0x9F'A9'1F'ff };
    constexpr uint32_t        CLARET{                                  0x7F'17'34'ff };
    constexpr uint32_t        COBALT_BLUE{                             0x00'47'AB'ff };
    constexpr uint32_t        COCOA_BROWN{                             0xD2'69'1E'ff };
    constexpr uint32_t        COFFEE{                                  0x6F'4E'37'ff };
    constexpr uint32_t        COLUMBIA_BLUE{                           0xB9'D9'EB'ff };
    constexpr uint32_t        CONGO_PINK{                              0xF8'83'79'ff };
    constexpr uint32_t        COOL_GREY{                               0x8C'92'AC'ff };
    constexpr uint32_t        COPPER{                                  0xB8'73'33'ff };
    constexpr uint32_t        COPPER_CRAYOLA{                          0xDA'8A'67'ff };
    constexpr uint32_t        COPPER_PENNY{                            0xAD'6F'69'ff };
    constexpr uint32_t        COPPER_RED{                              0xCB'6D'51'ff };
    constexpr uint32_t        COPPER_ROSE{                             0x99'66'66'ff };
    constexpr uint32_t        COQUELICOT{                              0xFF'38'00'ff };
    constexpr uint32_t        CORAL{                                   0xFF'7F'50'ff };
    constexpr uint32_t        CORAL_PINK{                              0xF8'83'79'ff };
    constexpr uint32_t        CORDOVAN{                                0x89'3F'45'ff };
    constexpr uint32_t        CORN{                                    0xFB'EC'5D'ff };
    constexpr uint32_t        CORNELL_RED{                             0xB3'1B'1B'ff };
    constexpr uint32_t        CORNFLOWER_BLUE{                         0x64'95'ED'ff };
    constexpr uint32_t        CORNSILK{                                0xFF'F8'DC'ff };
    constexpr uint32_t        COSMIC_COBALT{                           0x2E'2D'88'ff };
    constexpr uint32_t        COSMIC_LATTE{                            0xFF'F8'E7'ff };
    constexpr uint32_t        COYOTE_BROWN{                            0x81'61'3C'ff };
    constexpr uint32_t        COTTON_CANDY{                            0xFF'BC'D9'ff };
    constexpr uint32_t        CREAM{                                   0xFF'FD'D0'ff };
    constexpr uint32_t        CRIMSON{                                 0xDC'14'3C'ff };
    constexpr uint32_t        CRIMSON_UA{                              0x9E'1B'32'ff };
    constexpr uint32_t        CRYSTAL{                                 0xA7'D8'DE'ff };
    constexpr uint32_t        CULTURED{                                0xF5'F5'F5'ff };
    constexpr uint32_t        CYAN{                                    0x00'FF'FF'ff };
    constexpr uint32_t        CYAN_PROCESS{                            0x00'B7'EB'ff };
    constexpr uint32_t        CYBER_GRAPE{                             0x58'42'7C'ff };
    constexpr uint32_t        CYBER_YELLOW{                            0xFF'D3'00'ff };
    constexpr uint32_t        CYCLAMEN{                                0xF5'6F'A1'ff };
    constexpr uint32_t        DARK_BLUE_GRAY{                          0x66'66'99'ff };
    constexpr uint32_t        DARK_BROWN{                              0x65'43'21'ff };
    constexpr uint32_t        DARK_BYZANTIUM{                          0x5D'39'54'ff };
    constexpr uint32_t        DARK_CORNFLOWER_BLUE{                    0x26'42'8B'ff };
    constexpr uint32_t        DARK_CYAN{                               0x00'8B'8B'ff };
    constexpr uint32_t        DARK_ELECTRIC_BLUE{                      0x53'68'78'ff };
    constexpr uint32_t        DARK_GOLDENROD{                          0xB8'86'0B'ff };
    constexpr uint32_t        DARK_GREEN{                              0x01'32'20'ff };
    constexpr uint32_t        DARK_GREEN_X11{                          0x00'64'00'ff };
    constexpr uint32_t        DARK_JUNGLE_GREEN{                       0x1A'24'21'ff };
    constexpr uint32_t        DARK_KHAKI{                              0xBD'B7'6B'ff };
    constexpr uint32_t        DARK_LAVA{                               0x48'3C'32'ff };
    constexpr uint32_t        DARK_LIVER{                              0x53'4B'4F'ff };
    constexpr uint32_t        DARK_LIVER_HORSES{                       0x54'3D'37'ff };
    constexpr uint32_t        DARK_MAGENTA{                            0x8B'00'8B'ff };
    constexpr uint32_t        DARK_MOSS_GREEN{                         0x4A'5D'23'ff };
    constexpr uint32_t        DARK_OLIVE_GREEN{                        0x55'6B'2F'ff };
    constexpr uint32_t        DARK_ORANGE{                             0xFF'8C'00'ff };
    constexpr uint32_t        DARK_ORCHID{                             0x99'32'CC'ff };
    constexpr uint32_t        DARK_PASTEL_GREEN{                       0x03'C0'3C'ff };
    constexpr uint32_t        DARK_PURPLE{                             0x30'19'34'ff };
    constexpr uint32_t        DARK_RED{                                0x8B'00'00'ff };
    constexpr uint32_t        DARK_SALMON{                             0xE9'96'7A'ff };
    constexpr uint32_t        DARK_SEA_GREEN{                          0x8F'BC'8F'ff };
    constexpr uint32_t        DARK_SIENNA{                             0x3C'14'14'ff };
    constexpr uint32_t        DARK_SKY_BLUE{                           0x8C'BE'D6'ff };
    constexpr uint32_t        DARK_SLATE_BLUE{                         0x48'3D'8B'ff };
    constexpr uint32_t        DARK_SLATE_GRAY{                         0x2F'4F'4F'ff };
    constexpr uint32_t        DARK_SPRING_GREEN{                       0x17'72'45'ff };
    constexpr uint32_t        DARK_TURQUOISE{                          0x00'CE'D1'ff };
    constexpr uint32_t        DARK_VIOLET{                             0x94'00'D3'ff };
    constexpr uint32_t        DARTMOUTH_GREEN{                         0x00'70'3C'ff };
    constexpr uint32_t        DAVYS_GREY{                              0x55'55'55'ff };
    constexpr uint32_t        DEEP_CERISE{                             0xDA'32'87'ff };
    constexpr uint32_t        DEEP_CHAMPAGNE{                          0xFA'D6'A5'ff };
    constexpr uint32_t        DEEP_CHESTNUT{                           0xB9'4E'48'ff };
    constexpr uint32_t        DEEP_JUNGLE_GREEN{                       0x00'4B'49'ff };
    constexpr uint32_t        DEEP_PINK{                               0xFF'14'93'ff };
    constexpr uint32_t        DEEP_SAFFRON{                            0xFF'99'33'ff };
    constexpr uint32_t        DEEP_SKY_BLUE{                           0x00'BF'FF'ff };
    constexpr uint32_t        DEEP_SPACE_SPARKLE{                      0x4A'64'6C'ff };
    constexpr uint32_t        DEEP_TAUPE{                              0x7E'5E'60'ff };
    constexpr uint32_t        DENIM{                                   0x15'60'BD'ff };
    constexpr uint32_t        DENIM_BLUE{                              0x22'43'B6'ff };
    constexpr uint32_t        DESERT{                                  0xC1'9A'6B'ff };
    constexpr uint32_t        DESERT_SAND{                             0xED'C9'AF'ff };
    constexpr uint32_t        DIM_GRAY{                                0x69'69'69'ff };
    constexpr uint32_t        DODGER_BLUE{                             0x1E'90'FF'ff };
    constexpr uint32_t        DOGWOOD_ROSE{                            0xD7'18'68'ff };
    constexpr uint32_t        DRAB{                                    0x96'71'17'ff };
    constexpr uint32_t        DUKE_BLUE{                               0x00'00'9C'ff };
    constexpr uint32_t        DUTCH_WHITE{                             0xEF'DF'BB'ff };
    constexpr uint32_t        EARTH_YELLOW{                            0xE1'A9'5F'ff };
    constexpr uint32_t        EBONY{                                   0x55'5D'50'ff };
    constexpr uint32_t        ECRU{                                    0xC2'B2'80'ff };
    constexpr uint32_t        EERIE_BLACK{                             0x1B'1B'1B'ff };
    constexpr uint32_t        EGGPLANT{                                0x61'40'51'ff };
    constexpr uint32_t        EGGSHELL{                                0xF0'EA'D6'ff };
    constexpr uint32_t        EGYPTIAN_BLUE{                           0x10'34'A6'ff };
    constexpr uint32_t        EIGENGRAU{                               0x16'16'1D'ff };
    constexpr uint32_t        ELECTRIC_BLUE{                           0x7D'F9'FF'ff };
    constexpr uint32_t        ELECTRIC_GREEN{                          0x00'FF'00'ff };
    constexpr uint32_t        ELECTRIC_INDIGO{                         0x6F'00'FF'ff };
    constexpr uint32_t        ELECTRIC_LIME{                           0xCC'FF'00'ff };
    constexpr uint32_t        ELECTRIC_PURPLE{                         0xBF'00'FF'ff };
    constexpr uint32_t        ELECTRIC_VIOLET{                         0x8F'00'FF'ff };
    constexpr uint32_t        EMERALD{                                 0x50'C8'78'ff };
    constexpr uint32_t        EMINENCE{                                0x6C'30'82'ff };
    constexpr uint32_t        ENGLISH_GREEN{                           0x1B'4D'3E'ff };
    constexpr uint32_t        ENGLISH_LAVENDER{                        0xB4'83'95'ff };
    constexpr uint32_t        ENGLISH_RED{                             0xAB'4B'52'ff };
    constexpr uint32_t        ENGLISH_VERMILLION{                      0xCC'47'4B'ff };
    constexpr uint32_t        ENGLISH_VIOLET{                          0x56'3C'5C'ff };
    constexpr uint32_t        ERIN{                                    0x00'FF'40'ff };
    constexpr uint32_t        ETON_BLUE{                               0x96'C8'A2'ff };
    constexpr uint32_t        FALLOW{                                  0xC1'9A'6B'ff };
    constexpr uint32_t        FALU_RED{                                0x80'18'18'ff };
    constexpr uint32_t        FANDANGO{                                0xB5'33'89'ff };
    constexpr uint32_t        FANDANGO_PINK{                           0xDE'52'85'ff };
    constexpr uint32_t        FASHION_FUCHSIA{                         0xF4'00'A1'ff };
    constexpr uint32_t        FAWN{                                    0xE5'AA'70'ff };
    constexpr uint32_t        FELDGRAU{                                0x4D'5D'53'ff };
    constexpr uint32_t        FERN_GREEN{                              0x4F'79'42'ff };
    constexpr uint32_t        FIELD_DRAB{                              0x6C'54'1E'ff };
    constexpr uint32_t        FIERY_ROSE{                              0xFF'54'70'ff };
    constexpr uint32_t        FIREBRICK{                               0xB2'22'22'ff };
    constexpr uint32_t        FIRE_ENGINE_RED{                         0xCE'20'29'ff };
    constexpr uint32_t        FIRE_OPAL{                               0xE9'5C'4B'ff };
    constexpr uint32_t        FLAME{                                   0xE2'58'22'ff };
    constexpr uint32_t        FLAX{                                    0xEE'DC'82'ff };
    constexpr uint32_t        FLIRT{                                   0xA2'00'6D'ff };
    constexpr uint32_t        FLORAL_WHITE{                            0xFF'FA'F0'ff };
    constexpr uint32_t        FLUORESCENT_BLUE{                        0x15'F4'EE'ff };
    constexpr uint32_t        FOREST_GREEN_CRAYOLA{                    0x5F'A7'77'ff };
    constexpr uint32_t        FOREST_GREEN_TRADITIONAL{                0x01'44'21'ff };
    constexpr uint32_t        FOREST_GREEN_WEB{                        0x22'8B'22'ff };
    constexpr uint32_t        FRENCH_BEIGE{                            0xA6'7B'5B'ff };
    constexpr uint32_t        FRENCH_BISTRE{                           0x85'6D'4D'ff };
    constexpr uint32_t        FRENCH_BLUE{                             0x00'72'BB'ff };
    constexpr uint32_t        FRENCH_FUCHSIA{                          0xFD'3F'92'ff };
    constexpr uint32_t        FRENCH_LILAC{                            0x86'60'8E'ff };
    constexpr uint32_t        FRENCH_LIME{                             0x9E'FD'38'ff };
    constexpr uint32_t        FRENCH_MAUVE{                            0xD4'73'D4'ff };
    constexpr uint32_t        FRENCH_PINK{                             0xFD'6C'9E'ff };
    constexpr uint32_t        FRENCH_RASPBERRY{                        0xC7'2C'48'ff };
    constexpr uint32_t        FRENCH_ROSE{                             0xF6'4A'8A'ff };
    constexpr uint32_t        FRENCH_SKY_BLUE{                         0x77'B5'FE'ff };
    constexpr uint32_t        FRENCH_VIOLET{                           0x88'06'CE'ff };
    constexpr uint32_t        FROSTBITE{                               0xE9'36'A7'ff };
    constexpr uint32_t        FUCHSIA{                                 0xFF'00'FF'ff };
    constexpr uint32_t        FUCHSIA_CRAYOLA{                         0xC1'54'C1'ff };
    constexpr uint32_t        FUCHSIA_PURPLE{                          0xCC'39'7B'ff };
    constexpr uint32_t        FUCHSIA_ROSE{                            0xC7'43'75'ff };
    constexpr uint32_t        FULVOUS{                                 0xE4'84'00'ff };
    constexpr uint32_t        FUZZY_WUZZY{                             0x87'42'1F'ff };
    constexpr uint32_t        GAINSBORO{                               0xDC'DC'DC'ff };
    constexpr uint32_t        GAMBOGE{                                 0xE4'9B'0F'ff };
    constexpr uint32_t        GENERIC_VIRIDIAN{                        0x00'7F'66'ff };
    constexpr uint32_t        GHOST_WHITE{                             0xF8'F8'FF'ff };
    constexpr uint32_t        GLAUCOUS{                                0x60'82'B6'ff };
    constexpr uint32_t        GLOSSY_GRAPE{                            0xAB'92'B3'ff };
    constexpr uint32_t        GO_GREEN{                                0x00'AB'66'ff };
    constexpr uint32_t        GOLD{                                    0xA5'7C'00'ff };
    constexpr uint32_t        GOLD_METALLIC{                           0xD4'AF'37'ff };
    constexpr uint32_t        GOLDEN{                                  0xFF'D7'00'ff };
    constexpr uint32_t        GOLD_WEB{                                GOLDEN };
    constexpr uint32_t        GOLD_CRAYOLA{                            0xE6'BE'8A'ff };
    constexpr uint32_t        GOLD_FUSION{                             0x85'75'4E'ff };
    constexpr uint32_t        GOLDEN_BROWN{                            0x99'65'15'ff };
    constexpr uint32_t        GOLDEN_POPPY{                            0xFC'C2'00'ff };
    constexpr uint32_t        GOLDEN_YELLOW{                           0xFF'DF'00'ff };
    constexpr uint32_t        GOLDENROD{                               0xDA'A5'20'ff };
    constexpr uint32_t        GOTHAM_GREEN{                            0x00'57'3F'ff };
    constexpr uint32_t        GRANITE_GRAY{                            0x67'67'67'ff };
    constexpr uint32_t        GRANNY_SMITH_APPLE{                      0xA8'E4'A0'ff };
    constexpr uint32_t        GRAY{                                    0xBE'BE'BE'ff };
    constexpr uint32_t        GRAY_WEB{                                0x80'80'80'ff };
    constexpr uint32_t        GRAY_X11{                                GRAY };
    constexpr uint32_t        GREY{                                    GRAY };
    constexpr uint32_t        GREEN{                                   0x00'FF'00'ff };
    constexpr uint32_t        GREEN_CRAYOLA{                           0x1C'AC'78'ff };
    constexpr uint32_t        GREEN_WEB{                               0x00'80'00'ff };
    constexpr uint32_t        GREEN_MUNSELL{                           0x00'A8'77'ff };
    constexpr uint32_t        GREEN_NCS{                               0x00'9F'6B'ff };
    constexpr uint32_t        GREEN_PANTONE{                           0x00'AD'43'ff };
    constexpr uint32_t        GREEN_PIGMENT{                           0x00'A5'50'ff };
    constexpr uint32_t        GREEN_RYB{                               0x66'B0'32'ff };
    constexpr uint32_t        GREEN_BLUE{                              0x11'64'B4'ff };
    constexpr uint32_t        GREEN_BLUE_CRAYOLA{                      0x28'87'C8'ff };
    constexpr uint32_t        GREEN_CYAN{                              0x00'99'66'ff };
    constexpr uint32_t        GREEN_LIZARD{                            0xA7'F4'32'ff };
    constexpr uint32_t        GREEN_SHEEN{                             0x6E'AE'A1'ff };
    constexpr uint32_t        GREEN_YELLOW{                            0xAD'FF'2F'ff };
    constexpr uint32_t        GREEN_YELLOW_CRAYOLA{                    0xF0'E8'91'ff };
    constexpr uint32_t        GRULLO{                                  0xA9'9A'86'ff };
    constexpr uint32_t        GUNMETAL{                                0x2A'34'39'ff };
    constexpr uint32_t        HAN_BLUE{                                0x44'6C'CF'ff };
    constexpr uint32_t        HAN_PURPLE{                              0x52'18'FA'ff };
    constexpr uint32_t        HANSA_YELLOW{                            0xE9'D6'6B'ff };
    constexpr uint32_t        HARLEQUIN{                               0x3F'FF'00'ff };
    constexpr uint32_t        HARVEST_GOLD{                            0xDA'91'00'ff };
    constexpr uint32_t        HEAT_WAVE{                               0xFF'7A'00'ff };
    constexpr uint32_t        HELIOTROPE{                              0xDF'73'FF'ff };
    constexpr uint32_t        HELIOTROPE_GRAY{                         0xAA'98'A9'ff };
    constexpr uint32_t        HOLLYWOOD_CERISE{                        0xF4'00'A1'ff };
    constexpr uint32_t        HONEYDEW{                                0xF0'FF'F0'ff };
    constexpr uint32_t        HONOLULU_BLUE{                           0x00'6D'B0'ff };
    constexpr uint32_t        HOOKERS_GREEN{                           0x49'79'6B'ff };
    constexpr uint32_t        HOT_MAGENTA{                             0xFF'1D'CE'ff };
    constexpr uint32_t        HOT_PINK{                                0xFF'69'B4'ff };
    constexpr uint32_t        HUNTER_GREEN{                            0x35'5E'3B'ff };
    constexpr uint32_t        ICEBERG{                                 0x71'A6'D2'ff };
    constexpr uint32_t        ICTERINE{                                0xFC'F7'5E'ff };
    constexpr uint32_t        ILLUMINATING_EMERALD{                    0x31'91'77'ff };
    constexpr uint32_t        IMPERIAL_RED{                            0xED'29'39'ff };
    constexpr uint32_t        INCHWORM{                                0xB2'EC'5D'ff };
    constexpr uint32_t        INDEPENDENCE{                            0x4C'51'6D'ff };
    constexpr uint32_t        INDIA_GREEN{                             0x13'88'08'ff };
    constexpr uint32_t        INDIAN_RED{                              0xCD'5C'5C'ff };
    constexpr uint32_t        INDIAN_YELLOW{                           0xE3'A8'57'ff };
    constexpr uint32_t        INDIGO{                                  0x4B'00'82'ff };
    constexpr uint32_t        INDIGO_DYE{                              0x00'41'6A'ff };
    constexpr uint32_t        INTERNATIONAL_KLEIN_BLUE{                0x13'0A'8F'ff };
    constexpr uint32_t        INTERNATIONAL_ORANGE_AEROSPACE{          0xFF'4F'00'ff };
    constexpr uint32_t        INTERNATIONAL_ORANGE_ENGINEERING{        0xBA'16'0C'ff };
    constexpr uint32_t        INTERNATIONAL_ORANGE_GOLDEN_GATE_BRIDGE{ 0xC0'36'2C'ff };
    constexpr uint32_t        GOLDEN_GATE_BRIDGE_RED{                  INTERNATIONAL_ORANGE_GOLDEN_GATE_BRIDGE };
    constexpr uint32_t        IRIS{                                    0x5A'4F'CF'ff };
    constexpr uint32_t        IRRESISTIBLE{                            0xB3'44'6C'ff };
    constexpr uint32_t        ISABELLINE{                              0xF4'F0'EC'ff };
    constexpr uint32_t        ITALIAN_SKY_BLUE{                        0xB2'FF'FF'ff };
    constexpr uint32_t        IVORY{                                   0xFF'FF'F0'ff };
    constexpr uint32_t        JADE{                                    0x00'A8'6B'ff };
    constexpr uint32_t        JAPANESE_CARMINE{                        0x9D'29'33'ff };
    constexpr uint32_t        JAPANESE_VIOLET{                         0x5B'32'56'ff };
    constexpr uint32_t        JASMINE{                                 0xF8'DE'7E'ff };
    constexpr uint32_t        JAZZBERRY_JAM{                           0xA5'0B'5E'ff };
    constexpr uint32_t        JET{                                     0x34'34'34'ff };
    constexpr uint32_t        JONQUIL{                                 0xF4'CA'16'ff };
    constexpr uint32_t        JUNE_BUD{                                0xBD'DA'57'ff };
    constexpr uint32_t        JUNGLE_GREEN{                            0x29'AB'87'ff };
    constexpr uint32_t        KELLY_GREEN{                             0x4C'BB'17'ff };
    constexpr uint32_t        KEPPEL{                                  0x3A'B0'9E'ff };
    constexpr uint32_t        KEY_LIME{                                0xE8'F4'8C'ff };
    constexpr uint32_t        KHAKI_WEB{                               0xC3'B0'91'ff };
    constexpr uint32_t        KHAKI_X11{                               0xF0'E6'8C'ff };
    constexpr uint32_t        KOBE{                                    0x88'2D'17'ff };
    constexpr uint32_t        KOBI{                                    0xE7'9F'C4'ff };
    constexpr uint32_t        KOBICHA{                                 0x6B'44'23'ff };
    constexpr uint32_t        KOMBU_GREEN{                             0x35'42'30'ff };
    constexpr uint32_t        KSU_PURPLE{                              0x51'28'88'ff };
    constexpr uint32_t        LANGUID_LAVENDER{                        0xD6'CA'DD'ff };
    constexpr uint32_t        LAPIS_LAZULI{                            0x26'61'9C'ff };
    constexpr uint32_t        LASER_LEMON{                             0xFF'FF'66'ff };
    constexpr uint32_t        LAUREL_GREEN{                            0xA9'BA'9D'ff };
    constexpr uint32_t        LAVA{                                    0xCF'10'20'ff };
    constexpr uint32_t        LAVENDER_FLORAL{                         0xB5'7E'DC'ff };
    constexpr uint32_t        LAVENDER_WEB{                            0xE6'E6'FA'ff };
    constexpr uint32_t        LAVENDER_BLUE{                           0xCC'CC'FF'ff };
    constexpr uint32_t        LAVENDER_BLUSH{                          0xFF'F0'F5'ff };
    constexpr uint32_t        LAVENDER_GRAY{                           0xC4'C3'D0'ff };
    constexpr uint32_t        LAWN_GREEN{                              0x7C'FC'00'ff };
    constexpr uint32_t        LEMON{                                   0xFF'F7'00'ff };
    constexpr uint32_t        LEMON_CHIFFON{                           0xFF'FA'CD'ff };
    constexpr uint32_t        LEMON_CURRY{                             0xCC'A0'1D'ff };
    constexpr uint32_t        LEMON_GLACIER{                           0xFD'FF'00'ff };
    constexpr uint32_t        LEMON_MERINGUE{                          0xF6'EA'BE'ff };
    constexpr uint32_t        LEMON_YELLOW{                            0xFF'F4'4F'ff };
    constexpr uint32_t        LEMON_YELLOW_CRAYOLA{                    0xFF'FF'9F'ff };
    constexpr uint32_t        LIBERTY{                                 0x54'5A'A7'ff };
    constexpr uint32_t        LIGHT_BLUE{                              0xAD'D8'E6'ff };
    constexpr uint32_t        LIGHT_CORAL{                             0xF0'80'80'ff };
    constexpr uint32_t        LIGHT_CORNFLOWER_BLUE{                   0x93'CC'EA'ff };
    constexpr uint32_t        LIGHT_CYAN{                              0xE0'FF'FF'ff };
    constexpr uint32_t        LIGHT_FRENCH_BEIGE{                      0xC8'AD'7F'ff };
    constexpr uint32_t        LIGHT_GOLDENROD_YELLOW{                  0xFA'FA'D2'ff };
    constexpr uint32_t        LIGHT_GRAY{                              0xD3'D3'D3'ff };
    constexpr uint32_t        LIGHT_GREEN{                             0x90'EE'90'ff };
    constexpr uint32_t        LIGHT_KHAKI{                             KHAKI_X11 };
    constexpr uint32_t        LIGHT_ORANGE{                            0xFE'D8'B1'ff };
    constexpr uint32_t        LIGHT_PERIWINKLE{                        0xC5'CB'E1'ff };
    constexpr uint32_t        LIGHT_PINK{                              0xFF'B6'C1'ff };
    constexpr uint32_t        LIGHT_SALMON{                            0xFF'A0'7A'ff };
    constexpr uint32_t        LIGHT_SEA_GREEN{                         0x20'B2'AA'ff };
    constexpr uint32_t        LIGHT_SKY_BLUE{                          0x87'CE'FA'ff };
    constexpr uint32_t        LIGHT_SLATE_GRAY{                        0x77'88'99'ff };
    constexpr uint32_t        LIGHT_STEEL_BLUE{                        0xB0'C4'DE'ff };
    constexpr uint32_t        LIGHT_YELLOW{                            0xFF'FF'E0'ff };
    constexpr uint32_t        LILAC{                                   0xC8'A2'C8'ff };
    constexpr uint32_t        LILAC_LUSTER{                            0xAE'98'AA'ff };
    constexpr uint32_t        LIME_COLOR_WHEEL{                        0xBF'FF'00'ff };
    constexpr uint32_t        LIME_WEB{                                 GREEN };
    constexpr uint32_t        LIME_X11{                                 GREEN };
    constexpr uint32_t        LIME_GREEN{                              0x32'CD'32'ff };
    constexpr uint32_t        LINCOLN_GREEN{                           0x19'59'05'ff };
    constexpr uint32_t        LINEN{                                   0xFA'F0'E6'ff };
    constexpr uint32_t        LION{                                    0xC1'9A'6B'ff };
    constexpr uint32_t        LISERAN_PURPLE{                          0xDE'6F'A1'ff };
    constexpr uint32_t        LITTLE_BOY_BLUE{                         0x6C'A0'DC'ff };
    constexpr uint32_t        LIVER{                                   0x67'4C'47'ff };
    constexpr uint32_t        LIVER_DOGS{                              0xB8'6D'29'ff };
    constexpr uint32_t        LIVER_ORGAN{                             0x6C'2E'1F'ff };
    constexpr uint32_t        LIVER_CHESTNUT{                          0x98'74'56'ff };
    constexpr uint32_t        LIVID{                                   0x66'99'CC'ff };
    constexpr uint32_t        MACARONI_AND_CHEESE{                     0xFF'BD'88'ff };
    constexpr uint32_t        MADDER_LAKE{                             0xCC'33'36'ff };
    constexpr uint32_t        MAGENTA{                                 0xFF'00'FF'ff };
    constexpr uint32_t        MAGENTA_CRAYOLA{                         0xF6'53'A6'ff };
    constexpr uint32_t        MAGENTA_DYE{                             0xCA'1F'7B'ff };
    constexpr uint32_t        MAGENTA_PANTONE{                         0xD0'41'7E'ff };
    constexpr uint32_t        MAGENTA_PROCESS{                         0xFF'00'90'ff };
    constexpr uint32_t        MAGENTA_HAZE{                            0x9F'45'76'ff };
    constexpr uint32_t        MAGIC_MINT{                              0xAA'F0'D1'ff };
    constexpr uint32_t        MAGNOLIA{                                0xF2'E8'D7'ff };
    constexpr uint32_t        MAHOGANY{                                0xC0'40'00'ff };
    constexpr uint32_t        MAIZE{                                   0xFB'EC'5D'ff };
    constexpr uint32_t        MAIZE_CRAYOLA{                           0xF2'C6'49'ff };
    constexpr uint32_t        MAJORELLE_BLUE{                          0x60'50'DC'ff };
    constexpr uint32_t        MALACHITE{                               0x0B'DA'51'ff };
    constexpr uint32_t        MANATEE{                                 0x97'9A'AA'ff };
    constexpr uint32_t        MANDARIN{                                0xF3'7A'48'ff };
    constexpr uint32_t        MANGO{                                   0xFD'BE'02'ff };
    constexpr uint32_t        MANGO_TANGO{                             0xFF'82'43'ff };
    constexpr uint32_t        MANTIS{                                  0x74'C3'65'ff };
    constexpr uint32_t        MARDI_GRAS{                              0x88'00'85'ff };
    constexpr uint32_t        MARIGOLD{                                0xEA'A2'21'ff };
    constexpr uint32_t        MAROON_CRAYOLA{                          0xC3'21'48'ff };
    constexpr uint32_t        MAROON_WEB{                              0x80'00'00'ff };
    constexpr uint32_t        MAROON_X11{                              0xB0'30'60'ff };
    constexpr uint32_t        MAUVE{                                   0xE0'B0'FF'ff };
    constexpr uint32_t        MAUVE_TAUPE{                             0x91'5F'6D'ff };
    constexpr uint32_t        MAUVELOUS{                               0xEF'98'AA'ff };
    constexpr uint32_t        MAXIMUM_BLUE{                            0x47'AB'CC'ff };
    constexpr uint32_t        MAXIMUM_BLUE_GREEN{                      0x30'BF'BF'ff };
    constexpr uint32_t        MAXIMUM_BLUE_PURPLE{                     0xAC'AC'E6'ff };
    constexpr uint32_t        MAXIMUM_GREEN{                           0x5E'8C'31'ff };
    constexpr uint32_t        MAXIMUM_GREEN_YELLOW{                    0xD9'E6'50'ff };
    constexpr uint32_t        MAXIMUM_PURPLE{                          0x73'33'80'ff };
    constexpr uint32_t        MAXIMUM_RED{                             0xD9'21'21'ff };
    constexpr uint32_t        MAXIMUM_RED_PURPLE{                      0xA6'3A'79'ff };
    constexpr uint32_t        MAXIMUM_YELLOW{                          0xFA'FA'37'ff };
    constexpr uint32_t        MAXIMUM_YELLOW_RED{                      0xF2'BA'49'ff };
    constexpr uint32_t        MAY_GREEN{                               0x4C'91'41'ff };
    constexpr uint32_t        MAYA_BLUE{                               0x73'C2'FB'ff };
    constexpr uint32_t        MEDIUM_AQUAMARINE{                       0x66'DD'AA'ff };
    constexpr uint32_t        MEDIUM_BLUE{                             0x00'00'CD'ff };
    constexpr uint32_t        MEDIUM_CANDY_APPLE_RED{                  0xE2'06'2C'ff };
    constexpr uint32_t        MEDIUM_CARMINE{                          0xAF'40'35'ff };
    constexpr uint32_t        MEDIUM_CHAMPAGNE{                        0xF3'E5'AB'ff };
    constexpr uint32_t        MEDIUM_ORCHID{                           0xBA'55'D3'ff };
    constexpr uint32_t        MEDIUM_PURPLE{                           0x93'70'DB'ff };
    constexpr uint32_t        MEDIUM_SEA_GREEN{                        0x3C'B3'71'ff };
    constexpr uint32_t        MEDIUM_SLATE_BLUE{                       0x7B'68'EE'ff };
    constexpr uint32_t        MEDIUM_SPRING_GREEN{                     0x00'FA'9A'ff };
    constexpr uint32_t        MEDIUM_TURQUOISE{                        0x48'D1'CC'ff };
    constexpr uint32_t        MEDIUM_VIOLET_RED{                       0xC7'15'85'ff };
    constexpr uint32_t        MELLOW_APRICOT{                          0xF8'B8'78'ff };
    constexpr uint32_t        MELLOW_YELLOW{                           0xF8'DE'7E'ff };
    constexpr uint32_t        MELON{                                   0xFE'BA'AD'ff };
    constexpr uint32_t        METALLIC_GOLD{                           0xD3'AF'37'ff };
    constexpr uint32_t        METALLIC_SEAWEED{                        0x0A'7E'8C'ff };
    constexpr uint32_t        METALLIC_SUNBURST{                       0x9C'7C'38'ff };
    constexpr uint32_t        MEXICAN_PINK{                            0xE4'00'7C'ff };
    constexpr uint32_t        MIDDLE_BLUE{                             0x7E'D4'E6'ff };
    constexpr uint32_t        MIDDLE_BLUE_GREEN{                       0x8D'D9'CC'ff };
    constexpr uint32_t        MIDDLE_BLUE_PURPLE{                      0x8B'72'BE'ff };
    constexpr uint32_t        MIDDLE_GREY{                             0x8B'86'80'ff };
    constexpr uint32_t        MIDDLE_GREEN{                            0x4D'8C'57'ff };
    constexpr uint32_t        MIDDLE_GREEN_YELLOW{                     0xAC'BF'60'ff };
    constexpr uint32_t        MIDDLE_PURPLE{                           0xD9'82'B5'ff };
    constexpr uint32_t        MIDDLE_RED{                              0xE5'8E'73'ff };
    constexpr uint32_t        MIDDLE_RED_PURPLE{                       0xA5'53'53'ff };
    constexpr uint32_t        MIDDLE_YELLOW{                           0xFF'EB'00'ff };
    constexpr uint32_t        MIDDLE_YELLOW_RED{                       0xEC'B1'76'ff };
    constexpr uint32_t        MIDNIGHT{                                0x70'26'70'ff };
    constexpr uint32_t        MIDNIGHT_BLUE{                           0x19'19'70'ff };
    constexpr uint32_t        MIDNIGHT_GREEN{                          0x00'49'53'ff };
    constexpr uint32_t        EAGLE_GREEN{                             MIDNIGHT_GREEN };
    constexpr uint32_t        MIKADO_YELLOW{                           0xFF'C4'0C'ff };
    constexpr uint32_t        MIMI_PINK{                               0xFF'DA'E9'ff };
    constexpr uint32_t        MINDARO{                                 0xE3'F9'88'ff };
    constexpr uint32_t        MING{                                    0x36'74'7D'ff };
    constexpr uint32_t        MINION_YELLOW{                           0xF5'E0'50'ff };
    constexpr uint32_t        MINT{                                    0x3E'B4'89'ff };
    constexpr uint32_t        MINT_CREAM{                              0xF5'FF'FA'ff };
    constexpr uint32_t        MINT_GREEN{                              0x98'FF'98'ff };
    constexpr uint32_t        MISTY_MOSS{                              0xBB'B4'77'ff };
    constexpr uint32_t        MISTY_ROSE{                              0xFF'E4'E1'ff };
    constexpr uint32_t        MODE_BEIGE{                              0x96'71'17'ff };
    constexpr uint32_t        MORNING_BLUE{                            0x8D'A3'99'ff };
    constexpr uint32_t        MOSS_GREEN{                              0x8A'9A'5B'ff };
    constexpr uint32_t        MOUNTAIN_MEADOW{                         0x30'BA'8F'ff };
    constexpr uint32_t        MOUNTBATTEN_PINK{                        0x99'7A'8D'ff };
    constexpr uint32_t        MSU_GREEN{                               0x18'45'3B'ff };
    constexpr uint32_t        MULBERRY{                                0xC5'4B'8C'ff };
    constexpr uint32_t        MULBERRY_CRAYOLA{                        0xC8'50'9B'ff };
    constexpr uint32_t        MUSTARD{                                 0xFF'DB'58'ff };
    constexpr uint32_t        MYRTLE_GREEN{                            0x31'78'73'ff };
    constexpr uint32_t        MYSTIC{                                  0xD6'52'82'ff };
    constexpr uint32_t        MYSTIC_MAROON{                           0xAD'43'79'ff };
    constexpr uint32_t        NADESHIKO_PINK{                          0xF6'AD'C6'ff };
    constexpr uint32_t        NAPLES_YELLOW{                           0xFA'DA'5E'ff };
    constexpr uint32_t        NAVAJO_WHITE{                            0xFF'DE'AD'ff };
    constexpr uint32_t        NAVY_BLUE{                               0x00'00'80'ff };
    constexpr uint32_t        NAVY_BLUE_CRAYOLA{                       0x19'74'D2'ff };
    constexpr uint32_t        NEON_BLUE{                               0x46'66'FF'ff };
    constexpr uint32_t        NEON_CARROT{                             0xFF'A3'43'ff };
    constexpr uint32_t        NEON_GREEN{                              0x39'FF'14'ff };
    constexpr uint32_t        NEON_FUCHSIA{                            0xFE'41'64'ff };
    constexpr uint32_t        NEW_YORK_PINK{                           0xD7'83'7F'ff };
    constexpr uint32_t        NICKEL{                                  0x72'74'72'ff };
    constexpr uint32_t        NON_PHOTO_BLUE{                          0xA4'DD'ED'ff };
    constexpr uint32_t        NYANZA{                                  0xE9'FF'DB'ff };
    constexpr uint32_t        OCEAN_BLUE{                              0x4F'42'B5'ff };
    constexpr uint32_t        OCEAN_GREEN{                             0x48'BF'91'ff };
    constexpr uint32_t        OCHRE{                                   0xCC'77'22'ff };
    constexpr uint32_t        OLD_BURGUNDY{                            0x43'30'2E'ff };
    constexpr uint32_t        OLD_GOLD{                                0xCF'B5'3B'ff };
    constexpr uint32_t        OLD_LACE{                                0xFD'F5'E6'ff };
    constexpr uint32_t        OLD_LAVENDER{                            0x79'68'78'ff };
    constexpr uint32_t        OLD_MAUVE{                               0x67'31'47'ff };
    constexpr uint32_t        OLD_ROSE{                                0xC0'80'81'ff };
    constexpr uint32_t        OLD_SILVER{                              0x84'84'82'ff };
    constexpr uint32_t        OLIVE{                                   0x80'80'00'ff };
    constexpr uint32_t        OLIVE_DRAB_NUMBER_3{                     0x6B'8E'23'ff };
    constexpr uint32_t        OD3{                                     OLIVE_DRAB_NUMBER_3 };
    constexpr uint32_t        OLIVE_DRAB_NUMBER_7{                     0x3C'34'1F'ff };
    constexpr uint32_t        OD7{                                     OLIVE_DRAB_NUMBER_7 };
    constexpr uint32_t        OLIVE_GREEN{                             0xB5'B3'5C'ff };
    constexpr uint32_t        OLIVINE{                                 0x9A'B9'73'ff };
    constexpr uint32_t        ONYX{                                    0x35'38'39'ff };
    constexpr uint32_t        OPAL{                                    0xA8'C3'BC'ff };
    constexpr uint32_t        OPERA_MAUVE{                             0xB7'84'A7'ff };
    constexpr uint32_t        ORANGE{                                  0xFF'7F'00'ff };
    constexpr uint32_t        ORANGE_CRAYOLA{                          0xFF'75'38'ff };
    constexpr uint32_t        ORANGE_PANTONE{                          0xFF'58'00'ff };
    constexpr uint32_t        ORANGE_WEB{                              0xFF'A5'00'ff };
    constexpr uint32_t        ORANGE_PEEL{                             0xFF'9F'00'ff };
    constexpr uint32_t        ORANGE_RED{                              0xFF'68'1F'ff };
    constexpr uint32_t        ORANGE_RED_CRAYOLA{                      0xFF'53'49'ff };
    constexpr uint32_t        ORANGE_SODA{                             0xFA'5B'3D'ff };
    constexpr uint32_t        ORANGE_YELLOW{                           0xF5'BD'1F'ff };
    constexpr uint32_t        ORANGE_YELLOW_CRAYOLA{                   0xF8'D5'68'ff };
    constexpr uint32_t        ORCHID{                                  0xDA'70'D6'ff };
    constexpr uint32_t        ORCHID_PINK{                             0xF2'BD'CD'ff };
    constexpr uint32_t        ORCHID_CRAYOLA{                          0xE2'9C'D2'ff };
    constexpr uint32_t        OUTER_SPACE_CRAYOLA{                     0x2D'38'3A'ff };
    constexpr uint32_t        OUTRAGEOUS_ORANGE{                       0xFF'6E'4A'ff };
    constexpr uint32_t        OXBLOOD{                                 0x4A'00'00'ff };
    constexpr uint32_t        OXFORD_BLUE{                             0x00'21'47'ff };
    constexpr uint32_t        OU_CRIMSON_RED{                          0x84'16'17'ff };
    constexpr uint32_t        PACIFIC_BLUE{                            0x1C'A9'C9'ff };
    constexpr uint32_t        PAKISTAN_GREEN{                          0x00'66'00'ff };
    constexpr uint32_t        PALATINATE_PURPLE{                       0x68'28'60'ff };
    constexpr uint32_t        PALE_AQUA{                               0xBC'D4'E6'ff };
    constexpr uint32_t        PALE_CERULEAN{                           0x9B'C4'E2'ff };
    constexpr uint32_t        PALE_DOGWOOD{                            0xED'7A'9B'ff };
    constexpr uint32_t        PALE_PINK{                               0xFA'DA'DD'ff };
    constexpr uint32_t        PALE_PURPLE_PANTONE{                     0xFA'E6'FA'ff };
    constexpr uint32_t        PALE_SILVER{                             0xC9'C0'BB'ff };
    constexpr uint32_t        PALE_SPRING_BUD{                         0xEC'EB'BD'ff };
    constexpr uint32_t        PANSY_PURPLE{                            0x78'18'4A'ff };
    constexpr uint32_t        PAOLO_VERONESE_GREEN{                    0x00'9B'7D'ff };
    constexpr uint32_t        PAPAYA_WHIP{                             0xFF'EF'D5'ff };
    constexpr uint32_t        PARADISE_PINK{                           0xE6'3E'62'ff };
    constexpr uint32_t        PARCHMENT{                               0xF1'E9'D2'ff };
    constexpr uint32_t        PARIS_GREEN{                             0x50'C8'78'ff };
    constexpr uint32_t        PASTEL_PINK{                             0xDE'A5'A4'ff };
    constexpr uint32_t        PATRIARCH{                               0x80'00'80'ff };
    constexpr uint32_t        PAYNES_GREY{                             0x53'68'78'ff };
    constexpr uint32_t        PEACH{                                   0xFF'E5'B4'ff };
    constexpr uint32_t        PEACH_CRAYOLA{                           0xFF'CB'A4'ff };
    constexpr uint32_t        PEACH_PUFF{                              0xFF'DA'B9'ff };
    constexpr uint32_t        PEAR{                                    0xD1'E2'31'ff };
    constexpr uint32_t        PEARLY_PURPLE{                           0xB7'68'A2'ff };
    constexpr uint32_t        PERIWINKLE{                              0xCC'CC'FF'ff };
    constexpr uint32_t        PERIWINKLE_CRAYOLA{                      0xC3'CD'E6'ff };
    constexpr uint32_t        PERMANENT_GERANIUM_LAKE{                 0xE1'2C'2C'ff };
    constexpr uint32_t        PERSIAN_BLUE{                            0x1C'39'BB'ff };
    constexpr uint32_t        PERSIAN_GREEN{                           0x00'A6'93'ff };
    constexpr uint32_t        PERSIAN_INDIGO{                          0x32'12'7A'ff };
    constexpr uint32_t        PERSIAN_ORANGE{                          0xD9'90'58'ff };
    constexpr uint32_t        PERSIAN_PINK{                            0xF7'7F'BE'ff };
    constexpr uint32_t        PERSIAN_PLUM{                            0x70'1C'1C'ff };
    constexpr uint32_t        PERSIAN_RED{                             0xCC'33'33'ff };
    constexpr uint32_t        PERSIAN_ROSE{                            0xFE'28'A2'ff };
    constexpr uint32_t        PERSIMMON{                               0xEC'58'00'ff };
    constexpr uint32_t        PEWTER_BLUE{                             0x8B'A8'B7'ff };
    constexpr uint32_t        PHLOX{                                   0xDF'00'FF'ff };
    constexpr uint32_t        PHTHALO_BLUE{                            0x00'0F'89'ff };
    constexpr uint32_t        PHTHALO_GREEN{                           0x12'35'24'ff };
    constexpr uint32_t        PICOTEE_BLUE{                            0x2E'27'87'ff };
    constexpr uint32_t        PICTORIAL_CARMINE{                       0xC3'0B'4E'ff };
    constexpr uint32_t        PIGGY_PINK{                              0xFD'DD'E6'ff };
    constexpr uint32_t        PINE_GREEN{                              0x01'79'6F'ff };
    constexpr uint32_t        PINE_TREE{                               0x2A'2F'23'ff };
    constexpr uint32_t        PINK{                                    0xFF'C0'CB'ff };
    constexpr uint32_t        PINK_PANTONE{                            0xD7'48'94'ff };
    constexpr uint32_t        PINK_FLAMINGO{                           0xFC'74'FD'ff };
    constexpr uint32_t        PINK_LACE{                               0xFF'DD'F4'ff };
    constexpr uint32_t        PINK_LAVENDER{                           0xD8'B2'D1'ff };
    constexpr uint32_t        PINK_SHERBET{                            0xF7'8F'A7'ff };
    constexpr uint32_t        PISTACHIO{                               0x93'C5'72'ff };
    constexpr uint32_t        PLATINUM{                                0xE5'E4'E2'ff };
    constexpr uint32_t        PLUM{                                    0x8E'45'85'ff };
    constexpr uint32_t        PLUM_WEB{                                0xDD'A0'DD'ff };
    constexpr uint32_t        PLUMP_PURPLE{                            0x59'46'B2'ff };
    constexpr uint32_t        POLISHED_PINE{                           0x5D'A4'93'ff };
    constexpr uint32_t        POMP_AND_POWER{                          0x86'60'8E'ff };
    constexpr uint32_t        POPSTAR{                                 0xBE'4F'62'ff };
    constexpr uint32_t        PORTLAND_ORANGE{                         0xFF'5A'36'ff };
    constexpr uint32_t        POWDER_BLUE{                             0xB0'E0'E6'ff };
    constexpr uint32_t        PRINCETON_ORANGE{                        0xF5'80'25'ff };
    constexpr uint32_t        PROCESS_YELLOW{                          0xFF'EF'00'ff };
    constexpr uint32_t        PRUNE{                                   0x70'1C'1C'ff };
    constexpr uint32_t        PRUSSIAN_BLUE{                           0x00'31'53'ff };
    constexpr uint32_t        PSYCHEDELIC_PURPLE{                      0xDF'00'FF'ff };
    constexpr uint32_t        PUCE{                                    0xCC'88'99'ff };
    constexpr uint32_t        PULLMAN_BROWN{                           0x64'41'17'ff };
    constexpr uint32_t        UPS_BROWN{                               PULLMAN_BROWN };
    constexpr uint32_t        PUMPKIN{                                 0xFF'75'18'ff };
    constexpr uint32_t        PURPLE{                                  0x6A'0D'AD'ff };
    constexpr uint32_t        PURPLE_WEB{                              0x80'00'80'ff };
    constexpr uint32_t        PURPLE_MUNSELL{                          0x9F'00'C5'ff };
    constexpr uint32_t        PURPLE_X11{                              0xA0'20'F0'ff };
    constexpr uint32_t        PURPLE_MOUNTAIN_MAJESTY{                 0x96'78'B6'ff };
    constexpr uint32_t        PURPLE_NAVY{                             0x4E'51'80'ff };
    constexpr uint32_t        PURPLE_PIZZAZZ{                          0xFE'4E'DA'ff };
    constexpr uint32_t        PURPLE_PLUM{                             0x9C'51'B6'ff };
    constexpr uint32_t        PURPUREUS{                               0x9A'4E'AE'ff };
    constexpr uint32_t        QUEEN_BLUE{                              0x43'6B'95'ff };
    constexpr uint32_t        QUEEN_PINK{                              0xE8'CC'D7'ff };
    constexpr uint32_t        QUICK_SILVER{                            0xA6'A6'A6'ff };
    constexpr uint32_t        QUINACRIDONE_MAGENTA{                    0x8E'3A'59'ff };
    constexpr uint32_t        RADICAL_RED{                             0xFF'35'5E'ff };
    constexpr uint32_t        RAISIN_BLACK{                            0x24'21'24'ff };
    constexpr uint32_t        RAJAH{                                   0xFB'AB'60'ff };
    constexpr uint32_t        RASPBERRY{                               0xE3'0B'5D'ff };
    constexpr uint32_t        RASPBERRY_GLACE{                         0x91'5F'6D'ff };
    constexpr uint32_t        RASPBERRY_ROSE{                          0xB3'44'6C'ff };
    constexpr uint32_t        RAW_SIENNA{                              0xD6'8A'59'ff };
    constexpr uint32_t        RAW_UMBER{                               0x82'66'44'ff };
    constexpr uint32_t        RAZZLE_DAZZLE_ROSE{                      0xFF'33'CC'ff };
    constexpr uint32_t        RAZZMATAZZ{                              0xE3'25'6B'ff };
    constexpr uint32_t        RAZZMIC_BERRY{                           0x8D'4E'85'ff };
    constexpr uint32_t        REBECCA_PURPLE{                          0x66'33'99'ff };
    constexpr uint32_t        RED{                                     0xFF'00'00'ff };
    constexpr uint32_t        RED_CRAYOLA{                             0xEE'20'4D'ff };
    constexpr uint32_t        RED_MUNSELL{                             0xF2'00'3C'ff };
    constexpr uint32_t        RED_NCS{                                 0xC4'02'33'ff };
    constexpr uint32_t        RED_PANTONE{                             0xED'29'39'ff };
    constexpr uint32_t        RED_PIGMENT{                             0xED'1C'24'ff };
    constexpr uint32_t        RED_RYB{                                 0xFE'27'12'ff };
    constexpr uint32_t        RED_ORANGE{                              0xFF'53'49'ff };
    constexpr uint32_t        RED_ORANGE_CRAYOLA{                      0xFF'68'1F'ff };
    constexpr uint32_t        RED_ORANGE_COLOR_WHEEL{                  0xFF'45'00'ff };
    constexpr uint32_t        RED_PURPLE{                              0xE4'00'78'ff };
    constexpr uint32_t        RED_SALSA{                               0xFD'3A'4A'ff };
    constexpr uint32_t        RED_VIOLET{                              0xC7'15'85'ff };
    constexpr uint32_t        RED_VIOLET_CRAYOLA{                      0xC0'44'8F'ff };
    constexpr uint32_t        RED_VIOLET_COLOR_WHEEL{                  0x92'2B'3E'ff };
    constexpr uint32_t        REDWOOD{                                 0xA4'5A'52'ff };
    constexpr uint32_t        RESOLUTION_BLUE{                         0x00'23'87'ff };
    constexpr uint32_t        RHYTHM{                                  0x77'76'96'ff };
    constexpr uint32_t        RICH_BLACK{                              0x00'40'40'ff };
    constexpr uint32_t        RICH_BLACK_FOGRA29{                      0x01'0B'13'ff };
    constexpr uint32_t        RICH_BLACK_FOGRA39{                      0x01'02'03'ff };
    constexpr uint32_t        RIFLE_GREEN{                             0x44'4C'38'ff };
    constexpr uint32_t        ROBIN_EGG_BLUE{                          0x00'CC'CC'ff };
    constexpr uint32_t        ROCKET_METALLIC{                         0x8A'7F'80'ff };
    constexpr uint32_t        ROJO_SPANISH_RED{                        0xA9'11'01'ff };
    constexpr uint32_t        ROMAN_SILVER{                            0x83'89'96'ff };
    constexpr uint32_t        ROSE{                                    0xFF'00'7F'ff };
    constexpr uint32_t        ROSE_BONBON{                             0xF9'42'9E'ff };
    constexpr uint32_t        ROSE_DUST{                               0x9E'5E'6F'ff };
    constexpr uint32_t        ROSE_EBONY{                              0x67'48'46'ff };
    constexpr uint32_t        ROSE_MADDER{                             0xE3'26'36'ff };
    constexpr uint32_t        ROSE_PINK{                               0xFF'66'CC'ff };
    constexpr uint32_t        ROSE_POMPADOUR{                          0xED'7A'9B'ff };
    constexpr uint32_t        ROSE_QUARTZ{                             0xAA'98'A9'ff };
    constexpr uint32_t        ROSE_RED{                                0xC2'1E'56'ff };
    constexpr uint32_t        ROSE_TAUPE{                              0x90'5D'5D'ff };
    constexpr uint32_t        ROSE_VALE{                               0xAB'4E'52'ff };
    constexpr uint32_t        ROSEWOOD{                                0x65'00'0B'ff };
    constexpr uint32_t        ROSSO_CORSA{                             0xD4'00'00'ff };
    constexpr uint32_t        ROSY_BROWN{                              0xBC'8F'8F'ff };
    constexpr uint32_t        ROYAL_BLUE_DARK{                         0x00'23'66'ff };
    constexpr uint32_t        ROYAL_BLUE_LIGHT{                        0x41'69'E1'ff };
    constexpr uint32_t        ROYAL_PURPLE{                            0x78'51'A9'ff };
    constexpr uint32_t        ROYAL_YELLOW{                            0xFA'DA'5E'ff };
    constexpr uint32_t        RUBER{                                   0xCE'46'76'ff };
    constexpr uint32_t        RUBINE_RED{                              0xD1'00'56'ff };
    constexpr uint32_t        RUBY{                                    0xE0'11'5F'ff };
    constexpr uint32_t        RUBY_RED{                                0x9B'11'1E'ff };
    constexpr uint32_t        RUFOUS{                                  0xA8'1C'07'ff };
    constexpr uint32_t        RUSSET{                                  0x80'46'1B'ff };
    constexpr uint32_t        RUSSIAN_GREEN{                           0x67'92'67'ff };
    constexpr uint32_t        RUSSIAN_VIOLET{                          0x32'17'4D'ff };
    constexpr uint32_t        RUST{                                    0xB7'41'0E'ff };
    constexpr uint32_t        RUSTY_RED{                               0xDA'2C'43'ff };
    constexpr uint32_t        SACRAMENTO_STATE_GREEN{                  0x04'39'27'ff };
    constexpr uint32_t        SADDLE_BROWN{                            0x8B'45'13'ff };
    constexpr uint32_t        SAFETY_ORANGE_1{                         0xFF'78'00'ff };
    constexpr uint32_t        SAFETY_ORANGE_2{                         0xFF'67'00'ff };
    constexpr uint32_t        BLAZE_ORANGE{                            SAFETY_ORANGE_2 };
    constexpr uint32_t        SAFETY_YELLOW{                           0xEE'D2'02'ff };
    constexpr uint32_t        SAFFRON{                                 0xF4'C4'30'ff };
    constexpr uint32_t        SAGE{                                    0xBC'B8'8A'ff };
    constexpr uint32_t        ST_PATRICKS_BLUE{                        0x23'29'7A'ff };
    constexpr uint32_t        SALMON{                                  0xFA'80'72'ff };
    constexpr uint32_t        SALMON_PINK{                             0xFF'91'A4'ff };
    constexpr uint32_t        SAND{                                    0xC2'B2'80'ff };
    constexpr uint32_t        SAND_DUNE{                               0x96'71'17'ff };
    constexpr uint32_t        SANDY_BROWN{                             0xF4'A4'60'ff };
    constexpr uint32_t        SAP_GREEN{                               0x50'7D'2A'ff };
    constexpr uint32_t        SAPPHIRE{                                0x0F'52'BA'ff };
    constexpr uint32_t        SAPPHIRE_BLUE{                           0x00'67'A5'ff };
    constexpr uint32_t        SAPPHIRE_CRAYOLA{                        0x00'67'A5'ff };
    constexpr uint32_t        SATIN_SHEEN_GOLD{                        0xCB'A1'35'ff };
    constexpr uint32_t        SCARLET{                                 0xFF'24'00'ff };
    constexpr uint32_t        SCHAUSS_PINK{                            0xFF'91'AF'ff };
    constexpr uint32_t        SCHOOL_BUS_YELLOW{                       0xFF'D8'00'ff };
    constexpr uint32_t        SCREAMIN_GREEN{                          0x66'FF'66'ff };
    constexpr uint32_t        SEA_GREEN{                               0x2E'8B'57'ff };
    constexpr uint32_t        SEA_GREEN_CRAYOLA{                       0x00'FF'CD'ff };
    constexpr uint32_t        SEAL_BROWN{                              0x59'26'0B'ff };
    constexpr uint32_t        SEASHELL{                                0xFF'F5'EE'ff };
    constexpr uint32_t        SELECTIVE_YELLOW{                        0xFF'BA'00'ff };
    constexpr uint32_t        SEPIA{                                   0x70'42'14'ff };
    constexpr uint32_t        SHADOW{                                  0x8A'79'5D'ff };
    constexpr uint32_t        SHADOW_BLUE{                             0x77'8B'A5'ff };
    constexpr uint32_t        SHAMROCK_GREEN{                          0x00'9E'60'ff };
    constexpr uint32_t        SHEEN_GREEN{                             0x8F'D4'00'ff };
    constexpr uint32_t        SHIMMERING_BLUSH{                        0xD9'86'95'ff };
    constexpr uint32_t        SHINY_SHAMROCK{                          0x5F'A7'78'ff };
    constexpr uint32_t        SHOCKING_PINK{                           0xFC'0F'C0'ff };
    constexpr uint32_t        SHOCKING_PINK_CRAYOLA{                   0xFF'6F'FF'ff };
    constexpr uint32_t        SIENNA{                                  0x88'2D'17'ff };
    constexpr uint32_t        SILVER{                                  0xC0'C0'C0'ff };
    constexpr uint32_t        SILVER_CRAYOLA{                          0xC9'C0'BB'ff };
    constexpr uint32_t        SILVER_METALLIC{                         0xAA'A9'AD'ff };
    constexpr uint32_t        SILVER_CHALICE{                          0xAC'AC'AC'ff };
    constexpr uint32_t        SILVER_PINK{                             0xC4'AE'AD'ff };
    constexpr uint32_t        SILVER_SAND{                             0xBF'C1'C2'ff };
    constexpr uint32_t        SINOPIA{                                 0xCB'41'0B'ff };
    constexpr uint32_t        SIZZLING_RED{                            0xFF'38'55'ff };
    constexpr uint32_t        SIZZLING_SUNRISE{                        0xFF'DB'00'ff };
    constexpr uint32_t        SKOBELOFF{                               0x00'74'74'ff };
    constexpr uint32_t        SKY_BLUE{                                0x87'CE'EB'ff };
    constexpr uint32_t        SKY_BLUE_CRAYOLA{                        0x76'D7'EA'ff };
    constexpr uint32_t        SKY_MAGENTA{                             0xCF'71'AF'ff };
    constexpr uint32_t        SLATE_BLUE{                              0x6A'5A'CD'ff };
    constexpr uint32_t        SLATE_GRAY{                              0x70'80'90'ff };
    constexpr uint32_t        SLIMY_GREEN{                             0x29'96'17'ff };
    constexpr uint32_t        SMITTEN{                                 0xC8'41'86'ff };
    constexpr uint32_t        SMOKY_BLACK{                             0x10'0C'08'ff };
    constexpr uint32_t        SNOW{                                    0xFF'FA'FA'ff };
    constexpr uint32_t        SOLID_PINK{                              0x89'38'43'ff };
    constexpr uint32_t        SONIC_SILVER{                            0x75'75'75'ff };
    constexpr uint32_t        SPACE_CADET{                             0x1D'29'51'ff };
    constexpr uint32_t        SPANISH_BISTRE{                          0x80'75'32'ff };
    constexpr uint32_t        SPANISH_BLUE{                            0x00'70'B8'ff };
    constexpr uint32_t        SPANISH_CARMINE{                         0xD1'00'47'ff };
    constexpr uint32_t        SPANISH_GRAY{                            0x98'98'98'ff };
    constexpr uint32_t        SPANISH_GREEN{                           0x00'91'50'ff };
    constexpr uint32_t        SPANISH_ORANGE{                          0xE8'61'00'ff };
    constexpr uint32_t        SPANISH_PINK{                            0xF7'BF'BE'ff };
    constexpr uint32_t        SPANISH_RED{                             0xE6'00'26'ff };
    constexpr uint32_t        SPANISH_SKY_BLUE{                        0x00'FF'FF'ff };
    constexpr uint32_t        SPANISH_VIOLET{                          0x4C'28'82'ff };
    constexpr uint32_t        SPANISH_VIRIDIAN{                        0x00'7F'5C'ff };
    constexpr uint32_t        SPRING_BUD{                              0xA7'FC'00'ff };
    constexpr uint32_t        SPRING_FROST{                            0x87'FF'2A'ff };
    constexpr uint32_t        SPRING_GREEN{                            0x00'FF'7F'ff };
    constexpr uint32_t        SPRING_GREEN_CRAYOLA{                    0xEC'EB'BD'ff };
    constexpr uint32_t        STAR_COMMAND_BLUE{                       0x00'7B'B8'ff };
    constexpr uint32_t        STEEL_BLUE{                              0x46'82'B4'ff };
    constexpr uint32_t        STEEL_PINK{                              0xCC'33'CC'ff };
    constexpr uint32_t        STEEL_TEAL{                              0x5F'8A'8B'ff };
    constexpr uint32_t        STIL_DE_GRAIN_YELLOW{                    0xFA'DA'5E'ff };
    constexpr uint32_t        STRAW{                                   0xE4'D9'6F'ff };
    constexpr uint32_t        STRAWBERRY{                              0xFA'50'53'ff };
    constexpr uint32_t        STRAWBERRY_BLONDE{                       0xFF'93'61'ff };
    constexpr uint32_t        SUGAR_PLUM{                              0x91'4E'75'ff };
    constexpr uint32_t        SUNGLOW{                                 0xFF'CC'33'ff };
    constexpr uint32_t        SUNRAY{                                  0xE3'AB'57'ff };
    constexpr uint32_t        SUNSET{                                  0xFA'D6'A5'ff };
    constexpr uint32_t        SUPER_PINK{                              0xCF'6B'A9'ff };
    constexpr uint32_t        SWEET_BROWN{                             0xA8'37'31'ff };
    constexpr uint32_t        SYRACUSE_ORANGE{                         0xD4'45'00'ff };
    constexpr uint32_t        TAN{                                     0xD2'B4'8C'ff };
    constexpr uint32_t        TAN_CRAYOLA{                             0xD9'9A'6C'ff };
    constexpr uint32_t        TANGERINE{                               0xF2'85'00'ff };
    constexpr uint32_t        TANGO_PINK{                              0xE4'71'7A'ff };
    constexpr uint32_t        TART_ORANGE{                             0xFB'4D'46'ff };
    constexpr uint32_t        TAUPE{                                   0x48'3C'32'ff };
    constexpr uint32_t        TAUPE_GRAY{                              0x8B'85'89'ff };
    constexpr uint32_t        TEA_GREEN{                               0xD0'F0'C0'ff };
    constexpr uint32_t        TEA_ROSE_1{                              0xF8'83'79'ff };
    constexpr uint32_t        TEA_ROSE_2{                              0xF4'C2'C2'ff };
    constexpr uint32_t        TEAL{                                    0x00'80'80'ff };
    constexpr uint32_t        TEAL_BLUE{                               0x36'75'88'ff };
    constexpr uint32_t        TELEMAGENTA{                             0xCF'34'76'ff };
    constexpr uint32_t        TENNÉ_TAWNY{                             0xCD'57'00'ff };
    constexpr uint32_t        TENNE_TAWNY{                             TENNÉ_TAWNY };
    constexpr uint32_t        TERRA_COTTA{                             0xE2'72'5B'ff };
    constexpr uint32_t        THISTLE{                                 0xD8'BF'D8'ff };
    constexpr uint32_t        THULIAN_PINK{                            0xDE'6F'A1'ff };
    constexpr uint32_t        TICKLE_ME_PINK{                          0xFC'89'AC'ff };
    constexpr uint32_t        TIFFANY_BLUE{                            0x0A'BA'B5'ff };
    constexpr uint32_t        TIMBERWOLF{                              0xDB'D7'D2'ff };
    constexpr uint32_t        TITANIUM_YELLOW{                         0xEE'E6'00'ff };
    constexpr uint32_t        TOMATO{                                  0xFF'63'47'ff };
    constexpr uint32_t        TROPICAL_RAINFOREST{                     0x00'75'5E'ff };
    constexpr uint32_t        TRUE_BLUE{                               0x2D'68'C4'ff };
    constexpr uint32_t        TRYPAN_BLUE{                             0x1C'05'B3'ff };
    constexpr uint32_t        TUFTS_BLUE{                              0x3E'8E'DE'ff };
    constexpr uint32_t        TUMBLEWEED{                              0xDE'AA'88'ff };
    constexpr uint32_t        TURQUOISE{                               0x40'E0'D0'ff };
    constexpr uint32_t        TURQUOISE_BLUE{                          0x00'FF'EF'ff };
    constexpr uint32_t        TURQUOISE_GREEN{                         0xA0'D6'B4'ff };
    constexpr uint32_t        TURTLE_GREEN{                            0x8A'9A'5B'ff };
    constexpr uint32_t        TUSCAN{                                  0xFA'D6'A5'ff };
    constexpr uint32_t        TUSCAN_BROWN{                            0x6F'4E'37'ff };
    constexpr uint32_t        TUSCAN_RED{                              0x7C'48'48'ff };
    constexpr uint32_t        TUSCAN_TAN{                              0xA6'7B'5B'ff };
    constexpr uint32_t        TUSCANY{                                 0xC0'99'99'ff };
    constexpr uint32_t        TWILIGHT_LAVENDER{                       0x8A'49'6B'ff };
    constexpr uint32_t        TYRIAN_PURPLE{                           0x66'02'3C'ff };
    constexpr uint32_t        UA_BLUE{                                 0x00'33'AA'ff };
    constexpr uint32_t        UA_RED{                                  0xD9'00'4C'ff };
    constexpr uint32_t        ULTRAMARINE{                             0x3F'00'FF'ff };
    constexpr uint32_t        ULTRAMARINE_BLUE{                        0x41'66'F5'ff };
    constexpr uint32_t        ULTRA_PINK{                              0xFF'6F'FF'ff };
    constexpr uint32_t        ULTRA_RED{                               0xFC'6C'85'ff };
    constexpr uint32_t        UMBER{                                   0x63'51'47'ff };
    constexpr uint32_t        UNBLEACHED_SILK{                         0xFF'DD'CA'ff };
    constexpr uint32_t        UNITED_NATIONS_BLUE{                     0x5B'92'E5'ff };
    constexpr uint32_t        UNIVERSITY_OF_PENNSYLVANIA_RED{          0xA5'00'21'ff };
    constexpr uint32_t        UNMELLOW_YELLOW{                         0xFF'FF'66'ff };
    constexpr uint32_t        UP_FOREST_GREEN{                         0x01'44'21'ff };
    constexpr uint32_t        UP_MAROON{                               0x7B'11'13'ff };
    constexpr uint32_t        UPSDELL_RED{                             0xAE'20'29'ff };
    constexpr uint32_t        URANIAN_BLUE{                            0xAF'DB'F5'ff };
    constexpr uint32_t        USAFA_BLUE{                              0x00'4F'98'ff };
    constexpr uint32_t        UNITED_STATES_AIRFORCE_ACADEMY_BLUE{     USAFA_BLUE };
    constexpr uint32_t        VAN_DYKE_BROWN{                          0x66'42'28'ff };
    constexpr uint32_t        VANILLA{                                 0xF3'E5'AB'ff };
    constexpr uint32_t        VANILLA_ICE{                             0xF3'8F'A9'ff }; // Ice, ice, baby.
    constexpr uint32_t        VEGAS_GOLD{                              0xC5'B3'58'ff };
    constexpr uint32_t        VENETIAN_RED{                            0xC8'08'15'ff };
    constexpr uint32_t        VERDIGRIS{                               0x43'B3'AE'ff };
    constexpr uint32_t        VERMILION_1{                             0xE3'42'34'ff };
    constexpr uint32_t        VERMILION_2{                             0xD9'38'1E'ff };
    constexpr uint32_t        VERONICA{                                0xA0'20'F0'ff };
    constexpr uint32_t        VIOLET{                                  0x8F'00'FF'ff };
    constexpr uint32_t        VIOLET_COLOR_WHEEL{                      0x7F'00'FF'ff };
    constexpr uint32_t        VIOLET_CRAYOLA{                          0x96'3D'7F'ff };
    constexpr uint32_t        VIOLET_RYB{                              0x86'01'AF'ff };
    constexpr uint32_t        VIOLET_WEB{                              0xEE'82'EE'ff };
    constexpr uint32_t        VIOLET_BLUE{                             0x32'4A'B2'ff };
    constexpr uint32_t        VIOLET_BLUE_CRAYOLA{                     0x76'6E'C8'ff };
    constexpr uint32_t        VIOLET_RED{                              0xF7'53'94'ff };
    constexpr uint32_t        VIRIDIAN{                                0x40'82'6D'ff };
    constexpr uint32_t        VIRIDIAN_GREEN{                          0x00'96'98'ff };
    constexpr uint32_t        VIVID_BURGUNDY{                          0x9F'1D'35'ff };
    constexpr uint32_t        VIVID_SKY_BLUE{                          0x00'CC'FF'ff };
    constexpr uint32_t        VIVID_TANGERINE{                         0xFF'A0'89'ff };
    constexpr uint32_t        VIVID_VIOLET{                            0x9F'00'FF'ff };
    constexpr uint32_t        VOLT{                                    0xCE'FF'00'ff };
    constexpr uint32_t        WARM_BLACK{                              0x00'42'42'ff };
    constexpr uint32_t        WHEAT{                                   0xF5'DE'B3'ff };
    constexpr uint32_t        WHITE{                                   0xFF'FF'FF'ff };
    constexpr uint32_t        WILD_BLUE_YONDER{                        0xA2'AD'D0'ff };
    constexpr uint32_t        WILD_ORCHID{                             0xD4'70'A2'ff };
    constexpr uint32_t        WILD_STRAWBERRY{                         0xFF'43'A4'ff };
    constexpr uint32_t        WILD_WATERMELON{                         0xFC'6C'85'ff };
    constexpr uint32_t        WINDSOR_TAN{                             0xA7'55'02'ff };
    constexpr uint32_t        WINE{                                    0x72'2F'37'ff };
    constexpr uint32_t        WINE_DREGS{                              0x67'31'47'ff };
    constexpr uint32_t        WINTER_SKY{                              0xFF'00'7C'ff };
    constexpr uint32_t        WINTERGREEN_DREAM{                       0x56'88'7D'ff };
    constexpr uint32_t        WISTERIA{                                0xC9'A0'DC'ff };
    constexpr uint32_t        WOOD_BROWN{                              0xC1'9A'6B'ff };
    constexpr uint32_t        XANADU{                                  0x73'86'78'ff };
    constexpr uint32_t        XANTHIC{                                 0xEE'ED'09'ff };
    constexpr uint32_t        XANTHOUS{                                0xF1'B4'2F'ff };
    constexpr uint32_t        YALE_BLUE{                               0x00'35'6B'ff };
    constexpr uint32_t        YELLOW{                                  0xFF'FF'00'ff };
    constexpr uint32_t        YELLOW_CRAYOLA{                          0xFC'E8'83'ff };
    constexpr uint32_t        YELLOW_MUNSELL{                          0xEF'CC'00'ff };
    constexpr uint32_t        YELLOW_NCS{                              0xFF'D3'00'ff };
    constexpr uint32_t        YELLOW_PANTONE{                          0xFE'DF'00'ff };
    constexpr uint32_t        YELLOW_PROCESS{                          0xFF'EF'00'ff };
    constexpr uint32_t        YELLOW_RYB{                              0xFE'FE'33'ff };
    constexpr uint32_t        YELLOW_GREEN{                            0x9A'CD'32'ff };
    constexpr uint32_t        YELLOW_GREEN_CRAYOLA{                    0xC5'E3'84'ff };
    constexpr uint32_t        YELLOW_GREEN_COLOR_WHEEL{                0x30'B2'1A'ff };
    constexpr uint32_t        YELLOW_ORANGE{                           0xFF'AE'42'ff };
    constexpr uint32_t        YELLOW_ORANGE_COLOR_WHEEL{               0xFF'95'05'ff };
    constexpr uint32_t        YELLOW_SUNSHINE{                         0xFF'F7'00'ff };
    constexpr uint32_t        YINMN_BLUE{                              0x2E'50'90'ff };
    constexpr uint32_t        ZAFFRE{                                  0x00'14'A8'ff };
    constexpr uint32_t        ZOMP{                                    0x39'A7'8E'ff };

    constexpr uint32_t        PANTONE_448_C{                           0x4A'41'2A'ff };
}
#endif




#if defined(NAMED_COLORS_ENABLE_TUPLES)

#include<tuple>
namespace
{
#if defined(NAMED_COLORS_PREFER_ENUM)
    constexpr std::tuple<double, double, double, double> from_hex( hex_color color )
#else
    constexpr std::tuple<double, double, double, double> from_hex( const uint32_t& color )
#endif
    {
        return {
            static_cast<float>( ( static_cast<uint32_t>( color ) & 0xFF'00'00'00 ) >> 24 ) / 255.0f,
            static_cast<float>( ( static_cast<uint32_t>( color ) & 0x00'FF'00'00 ) >> 16 ) / 255.0f,
            static_cast<float>( ( static_cast<uint32_t>( color ) & 0x00'00'FF'00 ) >> 8 ) / 255.0f,
            static_cast<float>( ( static_cast<uint32_t>( color ) & 0x00'00'00'FF ) ) / 255.0f };
    }
}

constexpr auto         ABSOLUTE_ZERO{                           from_hex( hex_color::ABSOLUTE_ZERO ) };
constexpr auto         ACID_GREEN{                              from_hex( hex_color::ACID_GREEN ) };
constexpr auto         AERO{                                    from_hex( hex_color::AERO ) };
constexpr auto         AERO_BLUE{                               from_hex( hex_color::AERO_BLUE ) };
constexpr auto         AFRICAN_VIOLET{                          from_hex( hex_color::AFRICAN_VIOLET ) };
constexpr auto         AIR_SUPERIORITY_BLUE{                    from_hex( hex_color::AIR_SUPERIORITY_BLUE ) };
constexpr auto         ALABASTER{                               from_hex( hex_color::ALABASTER ) };
constexpr auto         ALICE_BLUE{                              from_hex( hex_color::ALICE_BLUE ) };
constexpr auto         ALLOY_ORANGE{                            from_hex( hex_color::ALLOY_ORANGE ) };
constexpr auto         ALMOND{                                  from_hex( hex_color::ALMOND ) };
constexpr auto         AMARANTH{                                from_hex( hex_color::AMARANTH ) };
constexpr auto         AMARANTH_M_AND_P{                        from_hex( hex_color::AMARANTH_M_AND_P ) };
constexpr auto         AMARANTH_PINK{                           from_hex( hex_color::AMARANTH_PINK ) };
constexpr auto         AMARANTH_PURPLE{                         from_hex( hex_color::AMARANTH_PURPLE ) };
constexpr auto         AMARANTH_RED{                            from_hex( hex_color::AMARANTH_RED ) };
constexpr auto         AMAZON{                                  from_hex( hex_color::AMAZON ) };
constexpr auto         AMBER{                                   from_hex( hex_color::AMBER ) };
constexpr auto         AMBER_SAE{                               from_hex( hex_color::AMBER_SAE ) };
constexpr auto         AMBER_ECE{                               from_hex( hex_color::AMBER_ECE ) };
constexpr auto         AMETHYST{                                from_hex( hex_color::AMETHYST ) };
constexpr auto         ANDROID_GREEN{                           from_hex( hex_color::ANDROID_GREEN ) };
constexpr auto         ANTIQUE_BRASS{                           from_hex( hex_color::ANTIQUE_BRASS ) };
constexpr auto         ANTIQUE_BRONZE{                          from_hex( hex_color::ANTIQUE_BRONZE ) };
constexpr auto         ANTIQUE_FUCHSIA{                         from_hex( hex_color::ANTIQUE_FUCHSIA ) };
constexpr auto         ANTIQUE_RUBY{                            from_hex( hex_color::ANTIQUE_RUBY ) };
constexpr auto         ANTIQUE_WHITE{                           from_hex( hex_color::ANTIQUE_WHITE ) };
constexpr auto         AO{                                      from_hex( hex_color::AO ) };
constexpr auto         APPLE_GREEN{                             from_hex( hex_color::APPLE_GREEN ) };
constexpr auto         APRICOT{                                 from_hex( hex_color::APRICOT ) };
constexpr auto         AQUA{                                    from_hex( hex_color::AQUA ) };
constexpr auto         AQUAMARINE{                              from_hex( hex_color::AQUAMARINE ) };
constexpr auto         ARCTIC_LIME{                             from_hex( hex_color::ARCTIC_LIME ) };
constexpr auto         ARMY_GREEN{                              from_hex( hex_color::ARMY_GREEN ) };
constexpr auto         ARTICHOKE{                               from_hex( hex_color::ARTICHOKE ) };
constexpr auto         ARYLIDE_YELLOW{                          from_hex( hex_color::ARYLIDE_YELLOW ) };
constexpr auto         ASH_GRAY{                                from_hex( hex_color::ASH_GRAY ) };
constexpr auto         ASPARAGUS{                               from_hex( hex_color::ASPARAGUS ) };
constexpr auto         ATOMIC_TANGERINE{                        from_hex( hex_color::ATOMIC_TANGERINE ) };
constexpr auto         AUBURN{                                  from_hex( hex_color::AUBURN ) };
constexpr auto         AUREOLIN{                                from_hex( hex_color::AUREOLIN ) };
constexpr auto         AVOCADO{                                 from_hex( hex_color::AVOCADO ) };
constexpr auto         AZURE{                                   from_hex( hex_color::AZURE ) };
constexpr auto         AZURE_X11{                               from_hex( hex_color::AZURE_X11 ) };
constexpr auto         AZURE_WEB{                               from_hex( hex_color::AZURE_WEB ) };
constexpr auto         BABY_BLUE{                               from_hex( hex_color::BABY_BLUE ) };
constexpr auto         BABY_BLUE_EYES{                          from_hex( hex_color::BABY_BLUE_EYES ) };
constexpr auto         BABY_PINK{                               from_hex( hex_color::BABY_PINK ) };
constexpr auto         BABY_POWDER{                             from_hex( hex_color::BABY_POWDER ) };
constexpr auto         BAKER_MILLER_PINK{                       from_hex( hex_color::BAKER_MILLER_PINK ) };
constexpr auto         BANANA_MANIA{                            from_hex( hex_color::BANANA_MANIA ) };
constexpr auto         BARBIE_PINK{                             from_hex( hex_color::BARBIE_PINK ) };
constexpr auto         BARN_RED{                                from_hex( hex_color::BARN_RED ) };
constexpr auto         BATTLESHIP_GREY{                         from_hex( hex_color::BATTLESHIP_GREY ) };
constexpr auto         BEAU_BLUE{                               from_hex( hex_color::BEAU_BLUE ) };
constexpr auto         BEAVER{                                  from_hex( hex_color::BEAVER ) };
constexpr auto         BEIGE{                                   from_hex( hex_color::BEIGE ) };
constexpr auto         B_DAZZLED_BLUE{                          from_hex( hex_color::B_DAZZLED_BLUE ) };
constexpr auto         BIG_DIP_O_RUBY{                          from_hex( hex_color::BIG_DIP_O_RUBY ) };
constexpr auto         BISQUE{                                  from_hex( hex_color::BISQUE ) };
constexpr auto         BISTRE{                                  from_hex( hex_color::BISTRE ) };
constexpr auto         BISTRE_BROWN{                            from_hex( hex_color::BISTRE_BROWN ) };
constexpr auto         BITTER_LEMON{                            from_hex( hex_color::BITTER_LEMON ) };
constexpr auto         BITTER_LIME{                             from_hex( hex_color::BITTER_LIME ) };
constexpr auto         BITTERSWEET{                             from_hex( hex_color::BITTERSWEET ) };
constexpr auto         BITTERSWEET_SHIMMER{                     from_hex( hex_color::BITTERSWEET_SHIMMER ) };
constexpr auto         BLACK{                                   from_hex( hex_color::BLACK ) };
constexpr auto         BLACK_BEAN{                              from_hex( hex_color::BLACK_BEAN ) };
constexpr auto         BLACK_CHOCOLATE{                         from_hex( hex_color::BLACK_CHOCOLATE ) };
constexpr auto         BLACK_COFFEE{                            from_hex( hex_color::BLACK_COFFEE ) };
constexpr auto         BLACK_CORAL{                             from_hex( hex_color::BLACK_CORAL ) };
constexpr auto         BLACK_OLIVE{                             from_hex( hex_color::BLACK_OLIVE ) };
constexpr auto         BLACK_SHADOWS{                           from_hex( hex_color::BLACK_SHADOWS ) };
constexpr auto         BLANCHED_ALMOND{                         from_hex( hex_color::BLANCHED_ALMOND ) };
constexpr auto         BLAST_OFF_BRONZE{                        from_hex( hex_color::BLAST_OFF_BRONZE ) };
constexpr auto         BLEU_DE_FRANCE{                          from_hex( hex_color::BLEU_DE_FRANCE ) };
constexpr auto         BLIZZARD_BLUE{                           from_hex( hex_color::BLIZZARD_BLUE ) };
constexpr auto         BLOND{                                   from_hex( hex_color::BLOND ) };
constexpr auto         BLOOD_RED{                               from_hex( hex_color::BLOOD_RED ) };
constexpr auto         BLUE{                                    from_hex( hex_color::BLUE ) };
constexpr auto         BLUE_CRAYOLA{                            from_hex( hex_color::BLUE_CRAYOLA ) };
constexpr auto         BLUE_MUNSELL{                            from_hex( hex_color::BLUE_MUNSELL ) };
constexpr auto         BLUE_NCS{                                from_hex( hex_color::BLUE_NCS ) };
constexpr auto         BLUE_PANTONE{                            from_hex( hex_color::BLUE_PANTONE ) };
constexpr auto         BLUE_PIGMENT{                            from_hex( hex_color::BLUE_PIGMENT ) };
constexpr auto         BLUE_RYB{                                from_hex( hex_color::BLUE_RYB ) };
constexpr auto         BLUE_BELL{                               from_hex( hex_color::BLUE_BELL ) };
constexpr auto         BLUE_GRAY{                               from_hex( hex_color::BLUE_GRAY ) };
constexpr auto         BLUE_GREEN{                              from_hex( hex_color::BLUE_GREEN ) };
constexpr auto         BLUE_GREEN_COLOR_WHEEL{                  from_hex( hex_color::BLUE_GREEN_COLOR_WHEEL ) };
constexpr auto         BLUE_JEANS{                              from_hex( hex_color::BLUE_JEANS ) };
constexpr auto         BLUE_SAPPHIRE{                           from_hex( hex_color::BLUE_SAPPHIRE ) };
constexpr auto         BLUE_VIOLET{                             from_hex( hex_color::BLUE_VIOLET ) };
constexpr auto         BLUE_VIOLET_CRAYOLA{                     from_hex( hex_color::BLUE_VIOLET_CRAYOLA ) };
constexpr auto         BLUE_VIOLET_COLOR_WHEEL{                 from_hex( hex_color::BLUE_VIOLET_COLOR_WHEEL ) };
constexpr auto         BLUE_YONDER{                             from_hex( hex_color::BLUE_YONDER ) };
constexpr auto         BLUETIFUL{                               from_hex( hex_color::BLUETIFUL ) };
constexpr auto         BLUSH{                                   from_hex( hex_color::BLUSH ) };
constexpr auto         BOLE{                                    from_hex( hex_color::BOLE ) };
constexpr auto         BONE{                                    from_hex( hex_color::BONE ) };
constexpr auto         BOTTLE_GREEN{                            from_hex( hex_color::BOTTLE_GREEN ) };
constexpr auto         BRANDY{                                  from_hex( hex_color::BRANDY ) };
constexpr auto         BRICK_RED{                               from_hex( hex_color::BRICK_RED ) };
constexpr auto         BRIGHT_GREEN{                            from_hex( hex_color::BRIGHT_GREEN ) };
constexpr auto         BRIGHT_LILAC{                            from_hex( hex_color::BRIGHT_LILAC ) };
constexpr auto         BRIGHT_MAROON{                           from_hex( hex_color::BRIGHT_MAROON ) };
constexpr auto         BRIGHT_NAVY_BLUE{                        from_hex( hex_color::BRIGHT_NAVY_BLUE ) };
constexpr auto         BRIGHT_YELLOW_CRAYOLA{                   from_hex( hex_color::BRIGHT_YELLOW_CRAYOLA ) };
constexpr auto         BRILLIANT_ROSE{                          from_hex( hex_color::BRILLIANT_ROSE ) };
constexpr auto         BRINK_PINK{                              from_hex( hex_color::BRINK_PINK ) };
constexpr auto         BRITISH_RACING_GREEN{                    from_hex( hex_color::BRITISH_RACING_GREEN ) };
constexpr auto         BRONZE{                                  from_hex( hex_color::BRONZE ) };
constexpr auto         BROWN{                                   from_hex( hex_color::BROWN ) };
constexpr auto         BROWN_SUGAR{                             from_hex( hex_color::BROWN_SUGAR ) };
constexpr auto         BRUNSWICK_GREEN{                         from_hex( hex_color::BRUNSWICK_GREEN ) };
constexpr auto         BUD_GREEN{                               from_hex( hex_color::BUD_GREEN ) };
constexpr auto         BUFF{                                    from_hex( hex_color::BUFF ) };
constexpr auto         BURGUNDY{                                from_hex( hex_color::BURGUNDY ) };
constexpr auto         BURLYWOOD{                               from_hex( hex_color::BURLYWOOD ) };
constexpr auto         BURNISHED_BROWN{                         from_hex( hex_color::BURNISHED_BROWN ) };
constexpr auto         BURNT_ORANGE{                            from_hex( hex_color::BURNT_ORANGE ) };
constexpr auto         BURNT_SIENNA{                            from_hex( hex_color::BURNT_SIENNA ) };
constexpr auto         BURNT_UMBER{                             from_hex( hex_color::BURNT_UMBER ) };
constexpr auto         BYZANTINE{                               from_hex( hex_color::BYZANTINE ) };
constexpr auto         BYZANTIUM{                               from_hex( hex_color::BYZANTIUM ) };
constexpr auto         CADET{                                   from_hex( hex_color::CADET ) };
constexpr auto         CADET_BLUE{                              from_hex( hex_color::CADET_BLUE ) };
constexpr auto         CADET_BLUE_CRAYOLA{                      from_hex( hex_color::CADET_BLUE_CRAYOLA ) };
constexpr auto         CADET_GREY{                              from_hex( hex_color::CADET_GREY ) };
constexpr auto         CADMIUM_GREEN{                           from_hex( hex_color::CADMIUM_GREEN ) };
constexpr auto         CADMIUM_ORANGE{                          from_hex( hex_color::CADMIUM_ORANGE ) };
constexpr auto         CADMIUM_RED{                             from_hex( hex_color::CADMIUM_RED ) };
constexpr auto         CADMIUM_YELLOW{                          from_hex( hex_color::CADMIUM_YELLOW ) };
constexpr auto         CAFÉ_AU_LAIT{                            from_hex( hex_color::CAFÉ_AU_LAIT ) };
constexpr auto         CAFE_AU_LAIT{                            from_hex( hex_color::CAFE_AU_LAIT ) };
constexpr auto         CAFÉ_NOIR{                               from_hex( hex_color::CAFÉ_NOIR ) };
constexpr auto         CAFE_NOIR{                               from_hex( hex_color::CAFE_NOIR ) };
constexpr auto         CAMBRIDGE_BLUE{                          from_hex( hex_color::CAMBRIDGE_BLUE ) };
constexpr auto         CAMEL{                                   from_hex( hex_color::CAMEL ) };
constexpr auto         CAMEO_PINK{                              from_hex( hex_color::CAMEO_PINK ) };
constexpr auto         CANARY{                                  from_hex( hex_color::CANARY ) };
constexpr auto         CANARY_YELLOW{                           from_hex( hex_color::CANARY_YELLOW ) };
constexpr auto         CANDY_APPLE_RED{                         from_hex( hex_color::CANDY_APPLE_RED ) };
constexpr auto         CANDY_PINK{                              from_hex( hex_color::CANDY_PINK ) };
constexpr auto         CAPRI{                                   from_hex( hex_color::CAPRI ) };
constexpr auto         CAPUT_MORTUUM{                           from_hex( hex_color::CAPUT_MORTUUM ) };
constexpr auto         CARDINAL{                                from_hex( hex_color::CARDINAL ) };
constexpr auto         CARIBBEAN_GREEN{                         from_hex( hex_color::CARIBBEAN_GREEN ) };
constexpr auto         CARMINE{                                 from_hex( hex_color::CARMINE ) };
constexpr auto         CARMINE_M_AND_P{                         from_hex( hex_color::CARMINE_M_AND_P ) };
constexpr auto         CARNATION_PINK{                          from_hex( hex_color::CARNATION_PINK ) };
constexpr auto         CARNELIAN{                               from_hex( hex_color::CARNELIAN ) };
constexpr auto         CAROLINA_BLUE{                           from_hex( hex_color::CAROLINA_BLUE ) };
constexpr auto         CARROT_ORANGE{                           from_hex( hex_color::CARROT_ORANGE ) };
constexpr auto         CASTLETON_GREEN{                         from_hex( hex_color::CASTLETON_GREEN ) };
constexpr auto         CATAWBA{                                 from_hex( hex_color::CATAWBA ) };
constexpr auto         CEDAR_CHEST{                             from_hex( hex_color::CEDAR_CHEST ) };
constexpr auto         CELADON{                                 from_hex( hex_color::CELADON ) };
constexpr auto         CELADON_BLUE{                            from_hex( hex_color::CELADON_BLUE ) };
constexpr auto         CELADON_GREEN{                           from_hex( hex_color::CELADON_GREEN ) };
constexpr auto         CELESTE{                                 from_hex( hex_color::CELESTE ) };
constexpr auto         CELTIC_BLUE{                             from_hex( hex_color::CELTIC_BLUE ) };
constexpr auto         CERISE{                                  from_hex( hex_color::CERISE ) };
constexpr auto         CERULEAN{                                from_hex( hex_color::CERULEAN ) };
constexpr auto         CERULEAN_BLUE{                           from_hex( hex_color::CERULEAN_BLUE ) };
constexpr auto         CERULEAN_FROST{                          from_hex( hex_color::CERULEAN_FROST ) };
constexpr auto         CERULEAN_CRAYOLA{                        from_hex( hex_color::CERULEAN_CRAYOLA ) };
constexpr auto         CG_BLUE{                                 from_hex( hex_color::CG_BLUE ) };
constexpr auto         CG_RED{                                  from_hex( hex_color::CG_RED ) };
constexpr auto         CHAMPAGN{                                from_hex( hex_color::CHAMPAGN ) };
constexpr auto         CHAMPAGNE_PINK{                          from_hex( hex_color::CHAMPAGNE_PINK ) };
constexpr auto         CHARCOAL{                                from_hex( hex_color::CHARCOAL ) };
constexpr auto         CHARLESTON_GREEN{                        from_hex( hex_color::CHARLESTON_GREEN ) };
constexpr auto         CHARM_PINK{                              from_hex( hex_color::CHARM_PINK ) };
constexpr auto         CHARTREUSE_TRADITIONAL{                  from_hex( hex_color::CHARTREUSE_TRADITIONAL ) };
constexpr auto         CHARTREUSE_WEB{                          from_hex( hex_color::CHARTREUSE_WEB ) };
constexpr auto         CHERRY_BLOSSOM_PINK{                     from_hex( hex_color::CHERRY_BLOSSOM_PINK ) };
constexpr auto         CHESTNUT{                                from_hex( hex_color::CHESTNUT ) };
constexpr auto         CHILI_RED{                               from_hex( hex_color::CHILI_RED ) };
constexpr auto         CHINA_PINK{                              from_hex( hex_color::CHINA_PINK ) };
constexpr auto         CHINA_ROSE{                              from_hex( hex_color::CHINA_ROSE ) };
constexpr auto         CHINESE_RED{                             from_hex( hex_color::CHINESE_RED ) };
constexpr auto         CHINESE_VIOLET{                          from_hex( hex_color::CHINESE_VIOLET ) };
constexpr auto         CHINESE_YELLOW{                          from_hex( hex_color::CHINESE_YELLOW ) };
constexpr auto         CHOCOLATE_TRADITIONAL{                   from_hex( hex_color::CHOCOLATE_TRADITIONAL ) };
constexpr auto         CHOCOLATE_WEB{                           from_hex( hex_color::CHOCOLATE_WEB ) };
constexpr auto         CHOCOLATE_COSMOS{                        from_hex( hex_color::CHOCOLATE_COSMOS ) };
constexpr auto         CHROME_YELLOW{                           from_hex( hex_color::CHROME_YELLOW ) };
constexpr auto         CINEREOUS{                               from_hex( hex_color::CINEREOUS ) };
constexpr auto         CINNABAR{                                from_hex( hex_color::CINNABAR ) };
constexpr auto         CINNAMON_SATIN{                          from_hex( hex_color::CINNAMON_SATIN ) };
constexpr auto         CITRINE{                                 from_hex( hex_color::CITRINE ) };
constexpr auto         CITRON{                                  from_hex( hex_color::CITRON ) };
constexpr auto         CLARET{                                  from_hex( hex_color::CLARET ) };
constexpr auto         COBALT_BLUE{                             from_hex( hex_color::COBALT_BLUE ) };
constexpr auto         COCOA_BROWN{                             from_hex( hex_color::COCOA_BROWN ) };
constexpr auto         COFFEE{                                  from_hex( hex_color::COFFEE ) };
constexpr auto         COLUMBIA_BLUE{                           from_hex( hex_color::COLUMBIA_BLUE ) };
constexpr auto         CONGO_PINK{                              from_hex( hex_color::CONGO_PINK ) };
constexpr auto         COOL_GREY{                               from_hex( hex_color::COOL_GREY ) };
constexpr auto         COPPER{                                  from_hex( hex_color::COPPER ) };
constexpr auto         COPPER_CRAYOLA{                          from_hex( hex_color::COPPER_CRAYOLA ) };
constexpr auto         COPPER_PENNY{                            from_hex( hex_color::COPPER_PENNY ) };
constexpr auto         COPPER_RED{                              from_hex( hex_color::COPPER_RED ) };
constexpr auto         COPPER_ROSE{                             from_hex( hex_color::COPPER_ROSE ) };
constexpr auto         COQUELICOT{                              from_hex( hex_color::COQUELICOT ) };
constexpr auto         CORAL{                                   from_hex( hex_color::CORAL ) };
constexpr auto         CORAL_PINK{                              from_hex( hex_color::CORAL_PINK ) };
constexpr auto         CORDOVAN{                                from_hex( hex_color::CORDOVAN ) };
constexpr auto         CORN{                                    from_hex( hex_color::CORN ) };
constexpr auto         CORNELL_RED{                             from_hex( hex_color::CORNELL_RED ) };
constexpr auto         CORNFLOWER_BLUE{                         from_hex( hex_color::CORNFLOWER_BLUE ) };
constexpr auto         CORNSILK{                                from_hex( hex_color::CORNSILK ) };
constexpr auto         COSMIC_COBALT{                           from_hex( hex_color::COSMIC_COBALT ) };
constexpr auto         COSMIC_LATTE{                            from_hex( hex_color::COSMIC_LATTE ) };
constexpr auto         COYOTE_BROWN{                            from_hex( hex_color::COYOTE_BROWN ) };
constexpr auto         COTTON_CANDY{                            from_hex( hex_color::COTTON_CANDY ) };
constexpr auto         CREAM{                                   from_hex( hex_color::CREAM ) };
constexpr auto         CRIMSON{                                 from_hex( hex_color::CRIMSON ) };
constexpr auto         CRIMSON_UA{                              from_hex( hex_color::CRIMSON_UA ) };
constexpr auto         CRYSTAL{                                 from_hex( hex_color::CRYSTAL ) };
constexpr auto         CULTURED{                                from_hex( hex_color::CULTURED ) };
constexpr auto         CYAN{                                    from_hex( hex_color::CYAN ) };
constexpr auto         CYAN_PROCESS{                            from_hex( hex_color::CYAN_PROCESS ) };
constexpr auto         CYBER_GRAPE{                             from_hex( hex_color::CYBER_GRAPE ) };
constexpr auto         CYBER_YELLOW{                            from_hex( hex_color::CYBER_YELLOW ) };
constexpr auto         CYCLAMEN{                                from_hex( hex_color::CYCLAMEN ) };
constexpr auto         DARK_BLUE_GRAY{                          from_hex( hex_color::DARK_BLUE_GRAY ) };
constexpr auto         DARK_BROWN{                              from_hex( hex_color::DARK_BROWN ) };
constexpr auto         DARK_BYZANTIUM{                          from_hex( hex_color::DARK_BYZANTIUM ) };
constexpr auto         DARK_CORNFLOWER_BLUE{                    from_hex( hex_color::DARK_CORNFLOWER_BLUE ) };
constexpr auto         DARK_CYAN{                               from_hex( hex_color::DARK_CYAN ) };
constexpr auto         DARK_ELECTRIC_BLUE{                      from_hex( hex_color::DARK_ELECTRIC_BLUE ) };
constexpr auto         DARK_GOLDENROD{                          from_hex( hex_color::DARK_GOLDENROD ) };
constexpr auto         DARK_GREEN{                              from_hex( hex_color::DARK_GREEN ) };
constexpr auto         DARK_GREEN_X11{                          from_hex( hex_color::DARK_GREEN_X11 ) };
constexpr auto         DARK_JUNGLE_GREEN{                       from_hex( hex_color::DARK_JUNGLE_GREEN ) };
constexpr auto         DARK_KHAKI{                              from_hex( hex_color::DARK_KHAKI ) };
constexpr auto         DARK_LAVA{                               from_hex( hex_color::DARK_LAVA ) };
constexpr auto         DARK_LIVER{                              from_hex( hex_color::DARK_LIVER ) };
constexpr auto         DARK_LIVER_HORSES{                       from_hex( hex_color::DARK_LIVER_HORSES ) };
constexpr auto         DARK_MAGENTA{                            from_hex( hex_color::DARK_MAGENTA ) };
constexpr auto         DARK_MOSS_GREEN{                         from_hex( hex_color::DARK_MOSS_GREEN ) };
constexpr auto         DARK_OLIVE_GREEN{                        from_hex( hex_color::DARK_OLIVE_GREEN ) };
constexpr auto         DARK_ORANGE{                             from_hex( hex_color::DARK_ORANGE ) };
constexpr auto         DARK_ORCHID{                             from_hex( hex_color::DARK_ORCHID ) };
constexpr auto         DARK_PASTEL_GREEN{                       from_hex( hex_color::DARK_PASTEL_GREEN ) };
constexpr auto         DARK_PURPLE{                             from_hex( hex_color::DARK_PURPLE ) };
constexpr auto         DARK_RED{                                from_hex( hex_color::DARK_RED ) };
constexpr auto         DARK_SALMON{                             from_hex( hex_color::DARK_SALMON ) };
constexpr auto         DARK_SEA_GREEN{                          from_hex( hex_color::DARK_SEA_GREEN ) };
constexpr auto         DARK_SIENNA{                             from_hex( hex_color::DARK_SIENNA ) };
constexpr auto         DARK_SKY_BLUE{                           from_hex( hex_color::DARK_SKY_BLUE ) };
constexpr auto         DARK_SLATE_BLUE{                         from_hex( hex_color::DARK_SLATE_BLUE ) };
constexpr auto         DARK_SLATE_GRAY{                         from_hex( hex_color::DARK_SLATE_GRAY ) };
constexpr auto         DARK_SPRING_GREEN{                       from_hex( hex_color::DARK_SPRING_GREEN ) };
constexpr auto         DARK_TURQUOISE{                          from_hex( hex_color::DARK_TURQUOISE ) };
constexpr auto         DARK_VIOLET{                             from_hex( hex_color::DARK_VIOLET ) };
constexpr auto         DARTMOUTH_GREEN{                         from_hex( hex_color::DARTMOUTH_GREEN ) };
constexpr auto         DAVYS_GREY{                              from_hex( hex_color::DAVYS_GREY ) };
constexpr auto         DEEP_CERISE{                             from_hex( hex_color::DEEP_CERISE ) };
constexpr auto         DEEP_CHAMPAGNE{                          from_hex( hex_color::DEEP_CHAMPAGNE ) };
constexpr auto         DEEP_CHESTNUT{                           from_hex( hex_color::DEEP_CHESTNUT ) };
constexpr auto         DEEP_JUNGLE_GREEN{                       from_hex( hex_color::DEEP_JUNGLE_GREEN ) };
constexpr auto         DEEP_PINK{                               from_hex( hex_color::DEEP_PINK ) };
constexpr auto         DEEP_SAFFRON{                            from_hex( hex_color::DEEP_SAFFRON ) };
constexpr auto         DEEP_SKY_BLUE{                           from_hex( hex_color::DEEP_SKY_BLUE ) };
constexpr auto         DEEP_SPACE_SPARKLE{                      from_hex( hex_color::DEEP_SPACE_SPARKLE ) };
constexpr auto         DEEP_TAUPE{                              from_hex( hex_color::DEEP_TAUPE ) };
constexpr auto         DENIM{                                   from_hex( hex_color::DENIM ) };
constexpr auto         DENIM_BLUE{                              from_hex( hex_color::DENIM_BLUE ) };
constexpr auto         DESERT{                                  from_hex( hex_color::DESERT ) };
constexpr auto         DESERT_SAND{                             from_hex( hex_color::DESERT_SAND ) };
constexpr auto         DIM_GRAY{                                from_hex( hex_color::DIM_GRAY ) };
constexpr auto         DODGER_BLUE{                             from_hex( hex_color::DODGER_BLUE ) };
constexpr auto         DOGWOOD_ROSE{                            from_hex( hex_color::DOGWOOD_ROSE ) };
constexpr auto         DRAB{                                    from_hex( hex_color::DRAB ) };
constexpr auto         DUKE_BLUE{                               from_hex( hex_color::DUKE_BLUE ) };
constexpr auto         DUTCH_WHITE{                             from_hex( hex_color::DUTCH_WHITE ) };
constexpr auto         EARTH_YELLOW{                            from_hex( hex_color::EARTH_YELLOW ) };
constexpr auto         EBONY{                                   from_hex( hex_color::EBONY ) };
constexpr auto         ECRU{                                    from_hex( hex_color::ECRU ) };
constexpr auto         EERIE_BLACK{                             from_hex( hex_color::EERIE_BLACK ) };
constexpr auto         EGGPLANT{                                from_hex( hex_color::EGGPLANT ) };
constexpr auto         EGGSHELL{                                from_hex( hex_color::EGGSHELL ) };
constexpr auto         EGYPTIAN_BLUE{                           from_hex( hex_color::EGYPTIAN_BLUE ) };
constexpr auto         EIGENGRAU{                               from_hex( hex_color::EIGENGRAU ) };
constexpr auto         ELECTRIC_BLUE{                           from_hex( hex_color::ELECTRIC_BLUE ) };
constexpr auto         ELECTRIC_GREEN{                          from_hex( hex_color::ELECTRIC_GREEN ) };
constexpr auto         ELECTRIC_INDIGO{                         from_hex( hex_color::ELECTRIC_INDIGO ) };
constexpr auto         ELECTRIC_LIME{                           from_hex( hex_color::ELECTRIC_LIME ) };
constexpr auto         ELECTRIC_PURPLE{                         from_hex( hex_color::ELECTRIC_PURPLE ) };
constexpr auto         ELECTRIC_VIOLET{                         from_hex( hex_color::ELECTRIC_VIOLET ) };
constexpr auto         EMERALD{                                 from_hex( hex_color::EMERALD ) };
constexpr auto         EMINENCE{                                from_hex( hex_color::EMINENCE ) };
constexpr auto         ENGLISH_GREEN{                           from_hex( hex_color::ENGLISH_GREEN ) };
constexpr auto         ENGLISH_LAVENDER{                        from_hex( hex_color::ENGLISH_LAVENDER ) };
constexpr auto         ENGLISH_RED{                             from_hex( hex_color::ENGLISH_RED ) };
constexpr auto         ENGLISH_VERMILLION{                      from_hex( hex_color::ENGLISH_VERMILLION ) };
constexpr auto         ENGLISH_VIOLET{                          from_hex( hex_color::ENGLISH_VIOLET ) };
constexpr auto         ERIN{                                    from_hex( hex_color::ERIN ) };
constexpr auto         ETON_BLUE{                               from_hex( hex_color::ETON_BLUE ) };
constexpr auto         FALLOW{                                  from_hex( hex_color::FALLOW ) };
constexpr auto         FALU_RED{                                from_hex( hex_color::FALU_RED ) };
constexpr auto         FANDANGO{                                from_hex( hex_color::FANDANGO ) };
constexpr auto         FANDANGO_PINK{                           from_hex( hex_color::FANDANGO_PINK ) };
constexpr auto         FASHION_FUCHSIA{                         from_hex( hex_color::FASHION_FUCHSIA ) };
constexpr auto         FAWN{                                    from_hex( hex_color::FAWN ) };
constexpr auto         FELDGRAU{                                from_hex( hex_color::FELDGRAU ) };
constexpr auto         FERN_GREEN{                              from_hex( hex_color::FERN_GREEN ) };
constexpr auto         FIELD_DRAB{                              from_hex( hex_color::FIELD_DRAB ) };
constexpr auto         FIERY_ROSE{                              from_hex( hex_color::FIERY_ROSE ) };
constexpr auto         FIREBRICK{                               from_hex( hex_color::FIREBRICK ) };
constexpr auto         FIRE_ENGINE_RED{                         from_hex( hex_color::FIRE_ENGINE_RED ) };
constexpr auto         FIRE_OPAL{                               from_hex( hex_color::FIRE_OPAL ) };
constexpr auto         FLAME{                                   from_hex( hex_color::FLAME ) };
constexpr auto         FLAX{                                    from_hex( hex_color::FLAX ) };
constexpr auto         FLIRT{                                   from_hex( hex_color::FLIRT ) };
constexpr auto         FLORAL_WHITE{                            from_hex( hex_color::FLORAL_WHITE ) };
constexpr auto         FLUORESCENT_BLUE{                        from_hex( hex_color::FLUORESCENT_BLUE ) };
constexpr auto         FOREST_GREEN_CRAYOLA{                    from_hex( hex_color::FOREST_GREEN_CRAYOLA ) };
constexpr auto         FOREST_GREEN_TRADITIONAL{                from_hex( hex_color::FOREST_GREEN_TRADITIONAL ) };
constexpr auto         FOREST_GREEN_WEB{                        from_hex( hex_color::FOREST_GREEN_WEB ) };
constexpr auto         FRENCH_BEIGE{                            from_hex( hex_color::FRENCH_BEIGE ) };
constexpr auto         FRENCH_BISTRE{                           from_hex( hex_color::FRENCH_BISTRE ) };
constexpr auto         FRENCH_BLUE{                             from_hex( hex_color::FRENCH_BLUE ) };
constexpr auto         FRENCH_FUCHSIA{                          from_hex( hex_color::FRENCH_FUCHSIA ) };
constexpr auto         FRENCH_LILAC{                            from_hex( hex_color::FRENCH_LILAC ) };
constexpr auto         FRENCH_LIME{                             from_hex( hex_color::FRENCH_LIME ) };
constexpr auto         FRENCH_MAUVE{                            from_hex( hex_color::FRENCH_MAUVE ) };
constexpr auto         FRENCH_PINK{                             from_hex( hex_color::FRENCH_PINK ) };
constexpr auto         FRENCH_RASPBERRY{                        from_hex( hex_color::FRENCH_RASPBERRY ) };
constexpr auto         FRENCH_ROSE{                             from_hex( hex_color::FRENCH_ROSE ) };
constexpr auto         FRENCH_SKY_BLUE{                         from_hex( hex_color::FRENCH_SKY_BLUE ) };
constexpr auto         FRENCH_VIOLET{                           from_hex( hex_color::FRENCH_VIOLET ) };
constexpr auto         FROSTBITE{                               from_hex( hex_color::FROSTBITE ) };
constexpr auto         FUCHSIA{                                 from_hex( hex_color::FUCHSIA ) };
constexpr auto         FUCHSIA_CRAYOLA{                         from_hex( hex_color::FUCHSIA_CRAYOLA ) };
constexpr auto         FUCHSIA_PURPLE{                          from_hex( hex_color::FUCHSIA_PURPLE ) };
constexpr auto         FUCHSIA_ROSE{                            from_hex( hex_color::FUCHSIA_ROSE ) };
constexpr auto         FULVOUS{                                 from_hex( hex_color::FULVOUS ) };
constexpr auto         FUZZY_WUZZY{                             from_hex( hex_color::FUZZY_WUZZY ) };
constexpr auto         GAINSBORO{                               from_hex( hex_color::GAINSBORO ) };
constexpr auto         GAMBOGE{                                 from_hex( hex_color::GAMBOGE ) };
constexpr auto         GENERIC_VIRIDIAN{                        from_hex( hex_color::GENERIC_VIRIDIAN ) };
constexpr auto         GHOST_WHITE{                             from_hex( hex_color::GHOST_WHITE ) };
constexpr auto         GLAUCOUS{                                from_hex( hex_color::GLAUCOUS ) };
constexpr auto         GLOSSY_GRAPE{                            from_hex( hex_color::GLOSSY_GRAPE ) };
constexpr auto         GO_GREEN{                                from_hex( hex_color::GO_GREEN ) };
constexpr auto         GOLD{                                    from_hex( hex_color::GOLD ) };
constexpr auto         GOLD_METALLIC{                           from_hex( hex_color::GOLD_METALLIC ) };
constexpr auto         GOLDEN{                                  from_hex( hex_color::GOLDEN ) };
constexpr auto         GOLD_WEB{                                from_hex( hex_color::GOLD_WEB ) };
constexpr auto         GOLD_CRAYOLA{                            from_hex( hex_color::GOLD_CRAYOLA ) };
constexpr auto         GOLD_FUSION{                             from_hex( hex_color::GOLD_FUSION ) };
constexpr auto         GOLDEN_BROWN{                            from_hex( hex_color::GOLDEN_BROWN ) };
constexpr auto         GOLDEN_POPPY{                            from_hex( hex_color::GOLDEN_POPPY ) };
constexpr auto         GOLDEN_YELLOW{                           from_hex( hex_color::GOLDEN_YELLOW ) };
constexpr auto         GOLDENROD{                               from_hex( hex_color::GOLDENROD ) };
constexpr auto         GOTHAM_GREEN{                            from_hex( hex_color::GOTHAM_GREEN ) };
constexpr auto         GRANITE_GRAY{                            from_hex( hex_color::GRANITE_GRAY ) };
constexpr auto         GRANNY_SMITH_APPLE{                      from_hex( hex_color::GRANNY_SMITH_APPLE ) };
constexpr auto         GRAY{                                    from_hex( hex_color::GRAY ) };
constexpr auto         GRAY_WEB{                                from_hex( hex_color::GRAY_WEB ) };
constexpr auto         GRAY_X11{                                from_hex( hex_color::GRAY_X11 ) };
constexpr auto         GREEN{                                   from_hex( hex_color::GREEN ) };
constexpr auto         GREEN_CRAYOLA{                           from_hex( hex_color::GREEN_CRAYOLA ) };
constexpr auto         GREEN_WEB{                               from_hex( hex_color::GREEN_WEB ) };
constexpr auto         GREEN_MUNSELL{                           from_hex( hex_color::GREEN_MUNSELL ) };
constexpr auto         GREEN_NCS{                               from_hex( hex_color::GREEN_NCS ) };
constexpr auto         GREEN_PANTONE{                           from_hex( hex_color::GREEN_PANTONE ) };
constexpr auto         GREEN_PIGMENT{                           from_hex( hex_color::GREEN_PIGMENT ) };
constexpr auto         GREEN_RYB{                               from_hex( hex_color::GREEN_RYB ) };
constexpr auto         GREEN_BLUE{                              from_hex( hex_color::GREEN_BLUE ) };
constexpr auto         GREEN_BLUE_CRAYOLA{                      from_hex( hex_color::GREEN_BLUE_CRAYOLA ) };
constexpr auto         GREEN_CYAN{                              from_hex( hex_color::GREEN_CYAN ) };
constexpr auto         GREEN_LIZARD{                            from_hex( hex_color::GREEN_LIZARD ) };
constexpr auto         GREEN_SHEEN{                             from_hex( hex_color::GREEN_SHEEN ) };
constexpr auto         GREEN_YELLOW{                            from_hex( hex_color::GREEN_YELLOW ) };
constexpr auto         GREEN_YELLOW_CRAYOLA{                    from_hex( hex_color::GREEN_YELLOW_CRAYOLA ) };
constexpr auto         GRULLO{                                  from_hex( hex_color::GRULLO ) };
constexpr auto         GUNMETAL{                                from_hex( hex_color::GUNMETAL ) };
constexpr auto         HAN_BLUE{                                from_hex( hex_color::HAN_BLUE ) };
constexpr auto         HAN_PURPLE{                              from_hex( hex_color::HAN_PURPLE ) };
constexpr auto         HANSA_YELLOW{                            from_hex( hex_color::HANSA_YELLOW ) };
constexpr auto         HARLEQUIN{                               from_hex( hex_color::HARLEQUIN ) };
constexpr auto         HARVEST_GOLD{                            from_hex( hex_color::HARVEST_GOLD ) };
constexpr auto         HEAT_WAVE{                               from_hex( hex_color::HEAT_WAVE ) };
constexpr auto         HELIOTROPE{                              from_hex( hex_color::HELIOTROPE ) };
constexpr auto         HELIOTROPE_GRAY{                         from_hex( hex_color::HELIOTROPE_GRAY ) };
constexpr auto         HOLLYWOOD_CERISE{                        from_hex( hex_color::HOLLYWOOD_CERISE ) };
constexpr auto         HONEYDEW{                                from_hex( hex_color::HONEYDEW ) };
constexpr auto         HONOLULU_BLUE{                           from_hex( hex_color::HONOLULU_BLUE ) };
constexpr auto         HOOKERS_GREEN{                           from_hex( hex_color::HOOKERS_GREEN ) };
constexpr auto         HOT_MAGENTA{                             from_hex( hex_color::HOT_MAGENTA ) };
constexpr auto         HOT_PINK{                                from_hex( hex_color::HOT_PINK ) };
constexpr auto         HUNTER_GREEN{                            from_hex( hex_color::HUNTER_GREEN ) };
constexpr auto         ICEBERG{                                 from_hex( hex_color::ICEBERG ) };
constexpr auto         ICTERINE{                                from_hex( hex_color::ICTERINE ) };
constexpr auto         ILLUMINATING_EMERALD{                    from_hex( hex_color::ILLUMINATING_EMERALD ) };
constexpr auto         IMPERIAL_RED{                            from_hex( hex_color::IMPERIAL_RED ) };
constexpr auto         INCHWORM{                                from_hex( hex_color::INCHWORM ) };
constexpr auto         INDEPENDENCE{                            from_hex( hex_color::INDEPENDENCE ) };
constexpr auto         INDIA_GREEN{                             from_hex( hex_color::INDIA_GREEN ) };
constexpr auto         INDIAN_RED{                              from_hex( hex_color::INDIAN_RED ) };
constexpr auto         INDIAN_YELLOW{                           from_hex( hex_color::INDIAN_YELLOW ) };
constexpr auto         INDIGO{                                  from_hex( hex_color::INDIGO ) };
constexpr auto         INDIGO_DYE{                              from_hex( hex_color::INDIGO_DYE ) };
constexpr auto         INTERNATIONAL_KLEIN_BLUE{                from_hex( hex_color::INTERNATIONAL_KLEIN_BLUE ) };
constexpr auto         INTERNATIONAL_ORANGE_AEROSPACE{          from_hex( hex_color::INTERNATIONAL_ORANGE_AEROSPACE ) };
constexpr auto         INTERNATIONAL_ORANGE_ENGINEERING{        from_hex( hex_color::INTERNATIONAL_ORANGE_ENGINEERING ) };
constexpr auto         INTERNATIONAL_ORANGE_GOLDEN_GATE_BRIDGE{ from_hex( hex_color::INTERNATIONAL_ORANGE_GOLDEN_GATE_BRIDGE ) };
constexpr auto         GOLDEN_GATE_BRIDGE_RED{                  from_hex( hex_color::GOLDEN_GATE_BRIDGE_RED ) };
constexpr auto         IRIS{                                    from_hex( hex_color::IRIS ) };
constexpr auto         IRRESISTIBLE{                            from_hex( hex_color::IRRESISTIBLE ) };
constexpr auto         ISABELLINE{                              from_hex( hex_color::ISABELLINE ) };
constexpr auto         ITALIAN_SKY_BLUE{                        from_hex( hex_color::ITALIAN_SKY_BLUE ) };
constexpr auto         IVORY{                                   from_hex( hex_color::IVORY ) };
constexpr auto         JADE{                                    from_hex( hex_color::JADE ) };
constexpr auto         JAPANESE_CARMINE{                        from_hex( hex_color::JAPANESE_CARMINE ) };
constexpr auto         JAPANESE_VIOLET{                         from_hex( hex_color::JAPANESE_VIOLET ) };
constexpr auto         JASMINE{                                 from_hex( hex_color::JASMINE ) };
constexpr auto         JAZZBERRY_JAM{                           from_hex( hex_color::JAZZBERRY_JAM ) };
constexpr auto         JET{                                     from_hex( hex_color::JET ) };
constexpr auto         JONQUIL{                                 from_hex( hex_color::JONQUIL ) };
constexpr auto         JUNE_BUD{                                from_hex( hex_color::JUNE_BUD ) };
constexpr auto         JUNGLE_GREEN{                            from_hex( hex_color::JUNGLE_GREEN ) };
constexpr auto         KELLY_GREEN{                             from_hex( hex_color::KELLY_GREEN ) };
constexpr auto         KEPPEL{                                  from_hex( hex_color::KEPPEL ) };
constexpr auto         KEY_LIME{                                from_hex( hex_color::KEY_LIME ) };
constexpr auto         KHAKI_WEB{                               from_hex( hex_color::KHAKI_WEB ) };
constexpr auto         KHAKI_X11{                               from_hex( hex_color::KHAKI_X11 ) };
constexpr auto         KOBE{                                    from_hex( hex_color::KOBE ) };
constexpr auto         KOBI{                                    from_hex( hex_color::KOBI ) };
constexpr auto         KOBICHA{                                 from_hex( hex_color::KOBICHA ) };
constexpr auto         KOMBU_GREEN{                             from_hex( hex_color::KOMBU_GREEN ) };
constexpr auto         KSU_PURPLE{                              from_hex( hex_color::KSU_PURPLE ) };
constexpr auto         LANGUID_LAVENDER{                        from_hex( hex_color::LANGUID_LAVENDER ) };
constexpr auto         LAPIS_LAZULI{                            from_hex( hex_color::LAPIS_LAZULI ) };
constexpr auto         LASER_LEMON{                             from_hex( hex_color::LASER_LEMON ) };
constexpr auto         LAUREL_GREEN{                            from_hex( hex_color::LAUREL_GREEN ) };
constexpr auto         LAVA{                                    from_hex( hex_color::LAVA ) };
constexpr auto         LAVENDER_FLORAL{                         from_hex( hex_color::LAVENDER_FLORAL ) };
constexpr auto         LAVENDER_WEB{                            from_hex( hex_color::LAVENDER_WEB ) };
constexpr auto         LAVENDER_BLUE{                           from_hex( hex_color::LAVENDER_BLUE ) };
constexpr auto         LAVENDER_BLUSH{                          from_hex( hex_color::LAVENDER_BLUSH ) };
constexpr auto         LAVENDER_GRAY{                           from_hex( hex_color::LAVENDER_GRAY ) };
constexpr auto         LAWN_GREEN{                              from_hex( hex_color::LAWN_GREEN ) };
constexpr auto         LEMON{                                   from_hex( hex_color::LEMON ) };
constexpr auto         LEMON_CHIFFON{                           from_hex( hex_color::LEMON_CHIFFON ) };
constexpr auto         LEMON_CURRY{                             from_hex( hex_color::LEMON_CURRY ) };
constexpr auto         LEMON_GLACIER{                           from_hex( hex_color::LEMON_GLACIER ) };
constexpr auto         LEMON_MERINGUE{                          from_hex( hex_color::LEMON_MERINGUE ) };
constexpr auto         LEMON_YELLOW{                            from_hex( hex_color::LEMON_YELLOW ) };
constexpr auto         LEMON_YELLOW_CRAYOLA{                    from_hex( hex_color::LEMON_YELLOW_CRAYOLA ) };
constexpr auto         LIBERTY{                                 from_hex( hex_color::LIBERTY ) };
constexpr auto         LIGHT_BLUE{                              from_hex( hex_color::LIGHT_BLUE ) };
constexpr auto         LIGHT_CORAL{                             from_hex( hex_color::LIGHT_CORAL ) };
constexpr auto         LIGHT_CORNFLOWER_BLUE{                   from_hex( hex_color::LIGHT_CORNFLOWER_BLUE ) };
constexpr auto         LIGHT_CYAN{                              from_hex( hex_color::LIGHT_CYAN ) };
constexpr auto         LIGHT_FRENCH_BEIGE{                      from_hex( hex_color::LIGHT_FRENCH_BEIGE ) };
constexpr auto         LIGHT_GOLDENROD_YELLOW{                  from_hex( hex_color::LIGHT_GOLDENROD_YELLOW ) };
constexpr auto         LIGHT_GRAY{                              from_hex( hex_color::LIGHT_GRAY ) };
constexpr auto         LIGHT_GREEN{                             from_hex( hex_color::LIGHT_GREEN ) };
constexpr auto         LIGHT_KHAKI{                             from_hex( hex_color::LIGHT_KHAKI ) };
constexpr auto         LIGHT_ORANGE{                            from_hex( hex_color::LIGHT_ORANGE ) };
constexpr auto         LIGHT_PERIWINKLE{                        from_hex( hex_color::LIGHT_PERIWINKLE ) };
constexpr auto         LIGHT_PINK{                              from_hex( hex_color::LIGHT_PINK ) };
constexpr auto         LIGHT_SALMON{                            from_hex( hex_color::LIGHT_SALMON ) };
constexpr auto         LIGHT_SEA_GREEN{                         from_hex( hex_color::LIGHT_SEA_GREEN ) };
constexpr auto         LIGHT_SKY_BLUE{                          from_hex( hex_color::LIGHT_SKY_BLUE ) };
constexpr auto         LIGHT_SLATE_GRAY{                        from_hex( hex_color::LIGHT_SLATE_GRAY ) };
constexpr auto         LIGHT_STEEL_BLUE{                        from_hex( hex_color::LIGHT_STEEL_BLUE ) };
constexpr auto         LIGHT_YELLOW{                            from_hex( hex_color::LIGHT_YELLOW ) };
constexpr auto         LILAC{                                   from_hex( hex_color::LILAC ) };
constexpr auto         LILAC_LUSTER{                            from_hex( hex_color::LILAC_LUSTER ) };
constexpr auto         LIME_COLOR_WHEEL{                        from_hex( hex_color::LIME_COLOR_WHEEL ) };
constexpr auto         LIME_WEB{                                from_hex( hex_color::LIME_WEB ) };
constexpr auto         LIME_X11{                                from_hex( hex_color::LIME_X11 ) };
constexpr auto         LIME_GREEN{                              from_hex( hex_color::LIME_GREEN ) };
constexpr auto         LINCOLN_GREEN{                           from_hex( hex_color::LINCOLN_GREEN ) };
constexpr auto         LINEN{                                   from_hex( hex_color::LINEN ) };
constexpr auto         LION{                                    from_hex( hex_color::LION ) };
constexpr auto         LISERAN_PURPLE{                          from_hex( hex_color::LISERAN_PURPLE ) };
constexpr auto         LITTLE_BOY_BLUE{                         from_hex( hex_color::LITTLE_BOY_BLUE ) };
constexpr auto         LIVER{                                   from_hex( hex_color::LIVER ) };
constexpr auto         LIVER_DOGS{                              from_hex( hex_color::LIVER_DOGS ) };
constexpr auto         LIVER_ORGAN{                             from_hex( hex_color::LIVER_ORGAN ) };
constexpr auto         LIVER_CHESTNUT{                          from_hex( hex_color::LIVER_CHESTNUT ) };
constexpr auto         LIVID{                                   from_hex( hex_color::LIVID ) };
constexpr auto         MACARONI_AND_CHEESE{                     from_hex( hex_color::MACARONI_AND_CHEESE ) };
constexpr auto         MADDER_LAKE{                             from_hex( hex_color::MADDER_LAKE ) };
constexpr auto         MAGENTA{                                 from_hex( hex_color::MAGENTA ) };
constexpr auto         MAGENTA_CRAYOLA{                         from_hex( hex_color::MAGENTA_CRAYOLA ) };
constexpr auto         MAGENTA_DYE{                             from_hex( hex_color::MAGENTA_DYE ) };
constexpr auto         MAGENTA_PANTONE{                         from_hex( hex_color::MAGENTA_PANTONE ) };
constexpr auto         MAGENTA_PROCESS{                         from_hex( hex_color::MAGENTA_PROCESS ) };
constexpr auto         MAGENTA_HAZE{                            from_hex( hex_color::MAGENTA_HAZE ) };
constexpr auto         MAGIC_MINT{                              from_hex( hex_color::MAGIC_MINT ) };
constexpr auto         MAGNOLIA{                                from_hex( hex_color::MAGNOLIA ) };
constexpr auto         MAHOGANY{                                from_hex( hex_color::MAHOGANY ) };
constexpr auto         MAIZE{                                   from_hex( hex_color::MAIZE ) };
constexpr auto         MAIZE_CRAYOLA{                           from_hex( hex_color::MAIZE_CRAYOLA ) };
constexpr auto         MAJORELLE_BLUE{                          from_hex( hex_color::MAJORELLE_BLUE ) };
constexpr auto         MALACHITE{                               from_hex( hex_color::MALACHITE ) };
constexpr auto         MANATEE{                                 from_hex( hex_color::MANATEE ) };
constexpr auto         MANDARIN{                                from_hex( hex_color::MANDARIN ) };
constexpr auto         MANGO{                                   from_hex( hex_color::MANGO ) };
constexpr auto         MANGO_TANGO{                             from_hex( hex_color::MANGO_TANGO ) };
constexpr auto         MANTIS{                                  from_hex( hex_color::MANTIS ) };
constexpr auto         MARDI_GRAS{                              from_hex( hex_color::MARDI_GRAS ) };
constexpr auto         MARIGOLD{                                from_hex( hex_color::MARIGOLD ) };
constexpr auto         MAROON_CRAYOLA{                          from_hex( hex_color::MAROON_CRAYOLA ) };
constexpr auto         MAROON_WEB{                              from_hex( hex_color::MAROON_WEB ) };
constexpr auto         MAROON_X11{                              from_hex( hex_color::MAROON_X11 ) };
constexpr auto         MAUVE{                                   from_hex( hex_color::MAUVE ) };
constexpr auto         MAUVE_TAUPE{                             from_hex( hex_color::MAUVE_TAUPE ) };
constexpr auto         MAUVELOUS{                               from_hex( hex_color::MAUVELOUS ) };
constexpr auto         MAXIMUM_BLUE{                            from_hex( hex_color::MAXIMUM_BLUE ) };
constexpr auto         MAXIMUM_BLUE_GREEN{                      from_hex( hex_color::MAXIMUM_BLUE_GREEN ) };
constexpr auto         MAXIMUM_BLUE_PURPLE{                     from_hex( hex_color::MAXIMUM_BLUE_PURPLE ) };
constexpr auto         MAXIMUM_GREEN{                           from_hex( hex_color::MAXIMUM_GREEN ) };
constexpr auto         MAXIMUM_GREEN_YELLOW{                    from_hex( hex_color::MAXIMUM_GREEN_YELLOW ) };
constexpr auto         MAXIMUM_PURPLE{                          from_hex( hex_color::MAXIMUM_PURPLE ) };
constexpr auto         MAXIMUM_RED{                             from_hex( hex_color::MAXIMUM_RED ) };
constexpr auto         MAXIMUM_RED_PURPLE{                      from_hex( hex_color::MAXIMUM_RED_PURPLE ) };
constexpr auto         MAXIMUM_YELLOW{                          from_hex( hex_color::MAXIMUM_YELLOW ) };
constexpr auto         MAXIMUM_YELLOW_RED{                      from_hex( hex_color::MAXIMUM_YELLOW_RED ) };
constexpr auto         MAY_GREEN{                               from_hex( hex_color::MAY_GREEN ) };
constexpr auto         MAYA_BLUE{                               from_hex( hex_color::MAYA_BLUE ) };
constexpr auto         MEDIUM_AQUAMARINE{                       from_hex( hex_color::MEDIUM_AQUAMARINE ) };
constexpr auto         MEDIUM_BLUE{                             from_hex( hex_color::MEDIUM_BLUE ) };
constexpr auto         MEDIUM_CANDY_APPLE_RED{                  from_hex( hex_color::MEDIUM_CANDY_APPLE_RED ) };
constexpr auto         MEDIUM_CARMINE{                          from_hex( hex_color::MEDIUM_CARMINE ) };
constexpr auto         MEDIUM_CHAMPAGNE{                        from_hex( hex_color::MEDIUM_CHAMPAGNE ) };
constexpr auto         MEDIUM_ORCHID{                           from_hex( hex_color::MEDIUM_ORCHID ) };
constexpr auto         MEDIUM_PURPLE{                           from_hex( hex_color::MEDIUM_PURPLE ) };
constexpr auto         MEDIUM_SEA_GREEN{                        from_hex( hex_color::MEDIUM_SEA_GREEN ) };
constexpr auto         MEDIUM_SLATE_BLUE{                       from_hex( hex_color::MEDIUM_SLATE_BLUE ) };
constexpr auto         MEDIUM_SPRING_GREEN{                     from_hex( hex_color::MEDIUM_SPRING_GREEN ) };
constexpr auto         MEDIUM_TURQUOISE{                        from_hex( hex_color::MEDIUM_TURQUOISE ) };
constexpr auto         MEDIUM_VIOLET_RED{                       from_hex( hex_color::MEDIUM_VIOLET_RED ) };
constexpr auto         MELLOW_APRICOT{                          from_hex( hex_color::MELLOW_APRICOT ) };
constexpr auto         MELLOW_YELLOW{                           from_hex( hex_color::MELLOW_YELLOW ) };
constexpr auto         MELON{                                   from_hex( hex_color::MELON ) };
constexpr auto         METALLIC_GOLD{                           from_hex( hex_color::METALLIC_GOLD ) };
constexpr auto         METALLIC_SEAWEED{                        from_hex( hex_color::METALLIC_SEAWEED ) };
constexpr auto         METALLIC_SUNBURST{                       from_hex( hex_color::METALLIC_SUNBURST ) };
constexpr auto         MEXICAN_PINK{                            from_hex( hex_color::MEXICAN_PINK ) };
constexpr auto         MIDDLE_BLUE{                             from_hex( hex_color::MIDDLE_BLUE ) };
constexpr auto         MIDDLE_BLUE_GREEN{                       from_hex( hex_color::MIDDLE_BLUE_GREEN ) };
constexpr auto         MIDDLE_BLUE_PURPLE{                      from_hex( hex_color::MIDDLE_BLUE_PURPLE ) };
constexpr auto         MIDDLE_GREY{                             from_hex( hex_color::MIDDLE_GREY ) };
constexpr auto         MIDDLE_GREEN{                            from_hex( hex_color::MIDDLE_GREEN ) };
constexpr auto         MIDDLE_GREEN_YELLOW{                     from_hex( hex_color::MIDDLE_GREEN_YELLOW ) };
constexpr auto         MIDDLE_PURPLE{                           from_hex( hex_color::MIDDLE_PURPLE ) };
constexpr auto         MIDDLE_RED{                              from_hex( hex_color::MIDDLE_RED ) };
constexpr auto         MIDDLE_RED_PURPLE{                       from_hex( hex_color::MIDDLE_RED_PURPLE ) };
constexpr auto         MIDDLE_YELLOW{                           from_hex( hex_color::MIDDLE_YELLOW ) };
constexpr auto         MIDDLE_YELLOW_RED{                       from_hex( hex_color::MIDDLE_YELLOW_RED ) };
constexpr auto         MIDNIGHT{                                from_hex( hex_color::MIDNIGHT ) };
constexpr auto         MIDNIGHT_BLUE{                           from_hex( hex_color::MIDNIGHT_BLUE ) };
constexpr auto         MIDNIGHT_GREEN{                          from_hex( hex_color::MIDNIGHT_GREEN ) };
constexpr auto         EAGLE_GREEN{                             from_hex( hex_color::EAGLE_GREEN ) };
constexpr auto         MIKADO_YELLOW{                           from_hex( hex_color::MIKADO_YELLOW ) };
constexpr auto         MIMI_PINK{                               from_hex( hex_color::MIMI_PINK ) };
constexpr auto         MINDARO{                                 from_hex( hex_color::MINDARO ) };
constexpr auto         MING{                                    from_hex( hex_color::MING ) };
constexpr auto         MINION_YELLOW{                           from_hex( hex_color::MINION_YELLOW ) };
constexpr auto         MINT{                                    from_hex( hex_color::MINT ) };
constexpr auto         MINT_CREAM{                              from_hex( hex_color::MINT_CREAM ) };
constexpr auto         MINT_GREEN{                              from_hex( hex_color::MINT_GREEN ) };
constexpr auto         MISTY_MOSS{                              from_hex( hex_color::MISTY_MOSS ) };
constexpr auto         MISTY_ROSE{                              from_hex( hex_color::MISTY_ROSE ) };
constexpr auto         MODE_BEIGE{                              from_hex( hex_color::MODE_BEIGE ) };
constexpr auto         MORNING_BLUE{                            from_hex( hex_color::MORNING_BLUE ) };
constexpr auto         MOSS_GREEN{                              from_hex( hex_color::MOSS_GREEN ) };
constexpr auto         MOUNTAIN_MEADOW{                         from_hex( hex_color::MOUNTAIN_MEADOW ) };
constexpr auto         MOUNTBATTEN_PINK{                        from_hex( hex_color::MOUNTBATTEN_PINK ) };
constexpr auto         MSU_GREEN{                               from_hex( hex_color::MSU_GREEN ) };
constexpr auto         MULBERRY{                                from_hex( hex_color::MULBERRY ) };
constexpr auto         MULBERRY_CRAYOLA{                        from_hex( hex_color::MULBERRY_CRAYOLA ) };
constexpr auto         MUSTARD{                                 from_hex( hex_color::MUSTARD ) };
constexpr auto         MYRTLE_GREEN{                            from_hex( hex_color::MYRTLE_GREEN ) };
constexpr auto         MYSTIC{                                  from_hex( hex_color::MYSTIC ) };
constexpr auto         MYSTIC_MAROON{                           from_hex( hex_color::MYSTIC_MAROON ) };
constexpr auto         NADESHIKO_PINK{                          from_hex( hex_color::NADESHIKO_PINK ) };
constexpr auto         NAPLES_YELLOW{                           from_hex( hex_color::NAPLES_YELLOW ) };
constexpr auto         NAVAJO_WHITE{                            from_hex( hex_color::NAVAJO_WHITE ) };
constexpr auto         NAVY_BLUE{                               from_hex( hex_color::NAVY_BLUE ) };
constexpr auto         NAVY_BLUE_CRAYOLA{                       from_hex( hex_color::NAVY_BLUE_CRAYOLA ) };
constexpr auto         NEON_BLUE{                               from_hex( hex_color::NEON_BLUE ) };
constexpr auto         NEON_CARROT{                             from_hex( hex_color::NEON_CARROT ) };
constexpr auto         NEON_GREEN{                              from_hex( hex_color::NEON_GREEN ) };
constexpr auto         NEON_FUCHSIA{                            from_hex( hex_color::NEON_FUCHSIA ) };
constexpr auto         NEW_YORK_PINK{                           from_hex( hex_color::NEW_YORK_PINK ) };
constexpr auto         NICKEL{                                  from_hex( hex_color::NICKEL ) };
constexpr auto         NON_PHOTO_BLUE{                          from_hex( hex_color::NON_PHOTO_BLUE ) };
constexpr auto         NYANZA{                                  from_hex( hex_color::NYANZA ) };
constexpr auto         OCEAN_BLUE{                              from_hex( hex_color::OCEAN_BLUE ) };
constexpr auto         OCEAN_GREEN{                             from_hex( hex_color::OCEAN_GREEN ) };
constexpr auto         OCHRE{                                   from_hex( hex_color::OCHRE ) };
constexpr auto         OLD_BURGUNDY{                            from_hex( hex_color::OLD_BURGUNDY ) };
constexpr auto         OLD_GOLD{                                from_hex( hex_color::OLD_GOLD ) };
constexpr auto         OLD_LACE{                                from_hex( hex_color::OLD_LACE ) };
constexpr auto         OLD_LAVENDER{                            from_hex( hex_color::OLD_LAVENDER ) };
constexpr auto         OLD_MAUVE{                               from_hex( hex_color::OLD_MAUVE ) };
constexpr auto         OLD_ROSE{                                from_hex( hex_color::OLD_ROSE ) };
constexpr auto         OLD_SILVER{                              from_hex( hex_color::OLD_SILVER ) };
constexpr auto         OLIVE{                                   from_hex( hex_color::OLIVE ) };
constexpr auto         OLIVE_DRAB_NUMBER_3{                     from_hex( hex_color::OLIVE_DRAB_NUMBER_3 ) };
constexpr auto         OD3{                                     from_hex( hex_color::OD3 ) };
constexpr auto         OLIVE_DRAB_NUMBER_7{                     from_hex( hex_color::OLIVE_DRAB_NUMBER_7 ) };
constexpr auto         OD7{                                     from_hex( hex_color::OD7 ) };
constexpr auto         OLIVE_GREEN{                             from_hex( hex_color::OLIVE_GREEN ) };
constexpr auto         OLIVINE{                                 from_hex( hex_color::OLIVINE ) };
constexpr auto         ONYX{                                    from_hex( hex_color::ONYX ) };
constexpr auto         OPAL{                                    from_hex( hex_color::OPAL ) };
constexpr auto         OPERA_MAUVE{                             from_hex( hex_color::OPERA_MAUVE ) };
constexpr auto         ORANGE{                                  from_hex( hex_color::ORANGE ) };
constexpr auto         ORANGE_CRAYOLA{                          from_hex( hex_color::ORANGE_CRAYOLA ) };
constexpr auto         ORANGE_PANTONE{                          from_hex( hex_color::ORANGE_PANTONE ) };
constexpr auto         ORANGE_WEB{                              from_hex( hex_color::ORANGE_WEB ) };
constexpr auto         ORANGE_PEEL{                             from_hex( hex_color::ORANGE_PEEL ) };
constexpr auto         ORANGE_RED{                              from_hex( hex_color::ORANGE_RED ) };
constexpr auto         ORANGE_RED_CRAYOLA{                      from_hex( hex_color::ORANGE_RED_CRAYOLA ) };
constexpr auto         ORANGE_SODA{                             from_hex( hex_color::ORANGE_SODA ) };
constexpr auto         ORANGE_YELLOW{                           from_hex( hex_color::ORANGE_YELLOW ) };
constexpr auto         ORANGE_YELLOW_CRAYOLA{                   from_hex( hex_color::ORANGE_YELLOW_CRAYOLA ) };
constexpr auto         ORCHID{                                  from_hex( hex_color::ORCHID ) };
constexpr auto         ORCHID_PINK{                             from_hex( hex_color::ORCHID_PINK ) };
constexpr auto         ORCHID_CRAYOLA{                          from_hex( hex_color::ORCHID_CRAYOLA ) };
constexpr auto         OUTER_SPACE_CRAYOLA{                     from_hex( hex_color::OUTER_SPACE_CRAYOLA ) };
constexpr auto         OUTRAGEOUS_ORANGE{                       from_hex( hex_color::OUTRAGEOUS_ORANGE ) };
constexpr auto         OXBLOOD{                                 from_hex( hex_color::OXBLOOD ) };
constexpr auto         OXFORD_BLUE{                             from_hex( hex_color::OXFORD_BLUE ) };
constexpr auto         OU_CRIMSON_RED{                          from_hex( hex_color::OU_CRIMSON_RED ) };
constexpr auto         PACIFIC_BLUE{                            from_hex( hex_color::PACIFIC_BLUE ) };
constexpr auto         PAKISTAN_GREEN{                          from_hex( hex_color::PAKISTAN_GREEN ) };
constexpr auto         PALATINATE_PURPLE{                       from_hex( hex_color::PALATINATE_PURPLE ) };
constexpr auto         PALE_AQUA{                               from_hex( hex_color::PALE_AQUA ) };
constexpr auto         PALE_CERULEAN{                           from_hex( hex_color::PALE_CERULEAN ) };
constexpr auto         PALE_DOGWOOD{                            from_hex( hex_color::PALE_DOGWOOD ) };
constexpr auto         PALE_PINK{                               from_hex( hex_color::PALE_PINK ) };
constexpr auto         PALE_PURPLE_PANTONE{                     from_hex( hex_color::PALE_PURPLE_PANTONE ) };
constexpr auto         PALE_SILVER{                             from_hex( hex_color::PALE_SILVER ) };
constexpr auto         PALE_SPRING_BUD{                         from_hex( hex_color::PALE_SPRING_BUD ) };
constexpr auto         PANSY_PURPLE{                            from_hex( hex_color::PANSY_PURPLE ) };
constexpr auto         PAOLO_VERONESE_GREEN{                    from_hex( hex_color::PAOLO_VERONESE_GREEN ) };
constexpr auto         PAPAYA_WHIP{                             from_hex( hex_color::PAPAYA_WHIP ) };
constexpr auto         PARADISE_PINK{                           from_hex( hex_color::PARADISE_PINK ) };
constexpr auto         PARCHMENT{                               from_hex( hex_color::PARCHMENT ) };
constexpr auto         PARIS_GREEN{                             from_hex( hex_color::PARIS_GREEN ) };
constexpr auto         PASTEL_PINK{                             from_hex( hex_color::PASTEL_PINK ) };
constexpr auto         PATRIARCH{                               from_hex( hex_color::PATRIARCH ) };
constexpr auto         PAYNES_GREY{                             from_hex( hex_color::PAYNES_GREY ) };
constexpr auto         PEACH{                                   from_hex( hex_color::PEACH ) };
constexpr auto         PEACH_CRAYOLA{                           from_hex( hex_color::PEACH_CRAYOLA ) };
constexpr auto         PEACH_PUFF{                              from_hex( hex_color::PEACH_PUFF ) };
constexpr auto         PEAR{                                    from_hex( hex_color::PEAR ) };
constexpr auto         PEARLY_PURPLE{                           from_hex( hex_color::PEARLY_PURPLE ) };
constexpr auto         PERIWINKLE{                              from_hex( hex_color::PERIWINKLE ) };
constexpr auto         PERIWINKLE_CRAYOLA{                      from_hex( hex_color::PERIWINKLE_CRAYOLA ) };
constexpr auto         PERMANENT_GERANIUM_LAKE{                 from_hex( hex_color::PERMANENT_GERANIUM_LAKE ) };
constexpr auto         PERSIAN_BLUE{                            from_hex( hex_color::PERSIAN_BLUE ) };
constexpr auto         PERSIAN_GREEN{                           from_hex( hex_color::PERSIAN_GREEN ) };
constexpr auto         PERSIAN_INDIGO{                          from_hex( hex_color::PERSIAN_INDIGO ) };
constexpr auto         PERSIAN_ORANGE{                          from_hex( hex_color::PERSIAN_ORANGE ) };
constexpr auto         PERSIAN_PINK{                            from_hex( hex_color::PERSIAN_PINK ) };
constexpr auto         PERSIAN_PLUM{                            from_hex( hex_color::PERSIAN_PLUM ) };
constexpr auto         PERSIAN_RED{                             from_hex( hex_color::PERSIAN_RED ) };
constexpr auto         PERSIAN_ROSE{                            from_hex( hex_color::PERSIAN_ROSE ) };
constexpr auto         PERSIMMON{                               from_hex( hex_color::PERSIMMON ) };
constexpr auto         PEWTER_BLUE{                             from_hex( hex_color::PEWTER_BLUE ) };
constexpr auto         PHLOX{                                   from_hex( hex_color::PHLOX ) };
constexpr auto         PHTHALO_BLUE{                            from_hex( hex_color::PHTHALO_BLUE ) };
constexpr auto         PHTHALO_GREEN{                           from_hex( hex_color::PHTHALO_GREEN ) };
constexpr auto         PICOTEE_BLUE{                            from_hex( hex_color::PICOTEE_BLUE ) };
constexpr auto         PICTORIAL_CARMINE{                       from_hex( hex_color::PICTORIAL_CARMINE ) };
constexpr auto         PIGGY_PINK{                              from_hex( hex_color::PIGGY_PINK ) };
constexpr auto         PINE_GREEN{                              from_hex( hex_color::PINE_GREEN ) };
constexpr auto         PINE_TREE{                               from_hex( hex_color::PINE_TREE ) };
constexpr auto         PINK{                                    from_hex( hex_color::PINK ) };
constexpr auto         PINK_PANTONE{                            from_hex( hex_color::PINK_PANTONE ) };
constexpr auto         PINK_FLAMINGO{                           from_hex( hex_color::PINK_FLAMINGO ) };
constexpr auto         PINK_LACE{                               from_hex( hex_color::PINK_LACE ) };
constexpr auto         PINK_LAVENDER{                           from_hex( hex_color::PINK_LAVENDER ) };
constexpr auto         PINK_SHERBET{                            from_hex( hex_color::PINK_SHERBET ) };
constexpr auto         PISTACHIO{                               from_hex( hex_color::PISTACHIO ) };
constexpr auto         PLATINUM{                                from_hex( hex_color::PLATINUM ) };
constexpr auto         PLUM{                                    from_hex( hex_color::PLUM ) };
constexpr auto         PLUM_WEB{                                from_hex( hex_color::PLUM_WEB ) };
constexpr auto         PLUMP_PURPLE{                            from_hex( hex_color::PLUMP_PURPLE ) };
constexpr auto         POLISHED_PINE{                           from_hex( hex_color::POLISHED_PINE ) };
constexpr auto         POMP_AND_POWER{                          from_hex( hex_color::POMP_AND_POWER ) };
constexpr auto         POPSTAR{                                 from_hex( hex_color::POPSTAR ) };
constexpr auto         PORTLAND_ORANGE{                         from_hex( hex_color::PORTLAND_ORANGE ) };
constexpr auto         POWDER_BLUE{                             from_hex( hex_color::POWDER_BLUE ) };
constexpr auto         PRINCETON_ORANGE{                        from_hex( hex_color::PRINCETON_ORANGE ) };
constexpr auto         PROCESS_YELLOW{                          from_hex( hex_color::PROCESS_YELLOW ) };
constexpr auto         PRUNE{                                   from_hex( hex_color::PRUNE ) };
constexpr auto         PRUSSIAN_BLUE{                           from_hex( hex_color::PRUSSIAN_BLUE ) };
constexpr auto         PSYCHEDELIC_PURPLE{                      from_hex( hex_color::PSYCHEDELIC_PURPLE ) };
constexpr auto         PUCE{                                    from_hex( hex_color::PUCE ) };
constexpr auto         PULLMAN_BROWN{                           from_hex( hex_color::PULLMAN_BROWN ) };
constexpr auto         UPS_BROWN{                               from_hex( hex_color::UPS_BROWN ) };
constexpr auto         PUMPKIN{                                 from_hex( hex_color::PUMPKIN ) };
constexpr auto         PURPLE{                                  from_hex( hex_color::PURPLE ) };
constexpr auto         PURPLE_WEB{                              from_hex( hex_color::PURPLE_WEB ) };
constexpr auto         PURPLE_MUNSELL{                          from_hex( hex_color::PURPLE_MUNSELL ) };
constexpr auto         PURPLE_X11{                              from_hex( hex_color::PURPLE_X11 ) };
constexpr auto         PURPLE_MOUNTAIN_MAJESTY{                 from_hex( hex_color::PURPLE_MOUNTAIN_MAJESTY ) };
constexpr auto         PURPLE_NAVY{                             from_hex( hex_color::PURPLE_NAVY ) };
constexpr auto         PURPLE_PIZZAZZ{                          from_hex( hex_color::PURPLE_PIZZAZZ ) };
constexpr auto         PURPLE_PLUM{                             from_hex( hex_color::PURPLE_PLUM ) };
constexpr auto         PURPUREUS{                               from_hex( hex_color::PURPUREUS ) };
constexpr auto         QUEEN_BLUE{                              from_hex( hex_color::QUEEN_BLUE ) };
constexpr auto         QUEEN_PINK{                              from_hex( hex_color::QUEEN_PINK ) };
constexpr auto         QUICK_SILVER{                            from_hex( hex_color::QUICK_SILVER ) };
constexpr auto         QUINACRIDONE_MAGENTA{                    from_hex( hex_color::QUINACRIDONE_MAGENTA ) };
constexpr auto         RADICAL_RED{                             from_hex( hex_color::RADICAL_RED ) };
constexpr auto         RAISIN_BLACK{                            from_hex( hex_color::RAISIN_BLACK ) };
constexpr auto         RAJAH{                                   from_hex( hex_color::RAJAH ) };
constexpr auto         RASPBERRY{                               from_hex( hex_color::RASPBERRY ) };
constexpr auto         RASPBERRY_GLACE{                         from_hex( hex_color::RASPBERRY_GLACE ) };
constexpr auto         RASPBERRY_ROSE{                          from_hex( hex_color::RASPBERRY_ROSE ) };
constexpr auto         RAW_SIENNA{                              from_hex( hex_color::RAW_SIENNA ) };
constexpr auto         RAW_UMBER{                               from_hex( hex_color::RAW_UMBER ) };
constexpr auto         RAZZLE_DAZZLE_ROSE{                      from_hex( hex_color::RAZZLE_DAZZLE_ROSE ) };
constexpr auto         RAZZMATAZZ{                              from_hex( hex_color::RAZZMATAZZ ) };
constexpr auto         RAZZMIC_BERRY{                           from_hex( hex_color::RAZZMIC_BERRY ) };
constexpr auto         REBECCA_PURPLE{                          from_hex( hex_color::REBECCA_PURPLE ) };
constexpr auto         RED{                                     from_hex( hex_color::RED ) };
constexpr auto         RED_CRAYOLA{                             from_hex( hex_color::RED_CRAYOLA ) };
constexpr auto         RED_MUNSELL{                             from_hex( hex_color::RED_MUNSELL ) };
constexpr auto         RED_NCS{                                 from_hex( hex_color::RED_NCS ) };
constexpr auto         RED_PANTONE{                             from_hex( hex_color::RED_PANTONE ) };
constexpr auto         RED_PIGMENT{                             from_hex( hex_color::RED_PIGMENT ) };
constexpr auto         RED_RYB{                                 from_hex( hex_color::RED_RYB ) };
constexpr auto         RED_ORANGE{                              from_hex( hex_color::RED_ORANGE ) };
constexpr auto         RED_ORANGE_CRAYOLA{                      from_hex( hex_color::RED_ORANGE_CRAYOLA ) };
constexpr auto         RED_ORANGE_COLOR_WHEEL{                  from_hex( hex_color::RED_ORANGE_COLOR_WHEEL ) };
constexpr auto         RED_PURPLE{                              from_hex( hex_color::RED_PURPLE ) };
constexpr auto         RED_SALSA{                               from_hex( hex_color::RED_SALSA ) };
constexpr auto         RED_VIOLET{                              from_hex( hex_color::RED_VIOLET ) };
constexpr auto         RED_VIOLET_CRAYOLA{                      from_hex( hex_color::RED_VIOLET_CRAYOLA ) };
constexpr auto         RED_VIOLET_COLOR_WHEEL{                  from_hex( hex_color::RED_VIOLET_COLOR_WHEEL ) };
constexpr auto         REDWOOD{                                 from_hex( hex_color::REDWOOD ) };
constexpr auto         RESOLUTION_BLUE{                         from_hex( hex_color::RESOLUTION_BLUE ) };
constexpr auto         RHYTHM{                                  from_hex( hex_color::RHYTHM ) };
constexpr auto         RICH_BLACK{                              from_hex( hex_color::RICH_BLACK ) };
constexpr auto         RICH_BLACK_FOGRA29{                      from_hex( hex_color::RICH_BLACK_FOGRA29 ) };
constexpr auto         RICH_BLACK_FOGRA39{                      from_hex( hex_color::RICH_BLACK_FOGRA39 ) };
constexpr auto         RIFLE_GREEN{                             from_hex( hex_color::RIFLE_GREEN ) };
constexpr auto         ROBIN_EGG_BLUE{                          from_hex( hex_color::ROBIN_EGG_BLUE ) };
constexpr auto         ROCKET_METALLIC{                         from_hex( hex_color::ROCKET_METALLIC ) };
constexpr auto         ROJO_SPANISH_RED{                        from_hex( hex_color::ROJO_SPANISH_RED ) };
constexpr auto         ROMAN_SILVER{                            from_hex( hex_color::ROMAN_SILVER ) };
constexpr auto         ROSE{                                    from_hex( hex_color::ROSE ) };
constexpr auto         ROSE_BONBON{                             from_hex( hex_color::ROSE_BONBON ) };
constexpr auto         ROSE_DUST{                               from_hex( hex_color::ROSE_DUST ) };
constexpr auto         ROSE_EBONY{                              from_hex( hex_color::ROSE_EBONY ) };
constexpr auto         ROSE_MADDER{                             from_hex( hex_color::ROSE_MADDER ) };
constexpr auto         ROSE_PINK{                               from_hex( hex_color::ROSE_PINK ) };
constexpr auto         ROSE_POMPADOUR{                          from_hex( hex_color::ROSE_POMPADOUR ) };
constexpr auto         ROSE_QUARTZ{                             from_hex( hex_color::ROSE_QUARTZ ) };
constexpr auto         ROSE_RED{                                from_hex( hex_color::ROSE_RED ) };
constexpr auto         ROSE_TAUPE{                              from_hex( hex_color::ROSE_TAUPE ) };
constexpr auto         ROSE_VALE{                               from_hex( hex_color::ROSE_VALE ) };
constexpr auto         ROSEWOOD{                                from_hex( hex_color::ROSEWOOD ) };
constexpr auto         ROSSO_CORSA{                             from_hex( hex_color::ROSSO_CORSA ) };
constexpr auto         ROSY_BROWN{                              from_hex( hex_color::ROSY_BROWN ) };
constexpr auto         ROYAL_BLUE_DARK{                         from_hex( hex_color::ROYAL_BLUE_DARK ) };
constexpr auto         ROYAL_BLUE_LIGHT{                        from_hex( hex_color::ROYAL_BLUE_LIGHT ) };
constexpr auto         ROYAL_PURPLE{                            from_hex( hex_color::ROYAL_PURPLE ) };
constexpr auto         ROYAL_YELLOW{                            from_hex( hex_color::ROYAL_YELLOW ) };
constexpr auto         RUBER{                                   from_hex( hex_color::RUBER ) };
constexpr auto         RUBINE_RED{                              from_hex( hex_color::RUBINE_RED ) };
constexpr auto         RUBY{                                    from_hex( hex_color::RUBY ) };
constexpr auto         RUBY_RED{                                from_hex( hex_color::RUBY_RED ) };
constexpr auto         RUFOUS{                                  from_hex( hex_color::RUFOUS ) };
constexpr auto         RUSSET{                                  from_hex( hex_color::RUSSET ) };
constexpr auto         RUSSIAN_GREEN{                           from_hex( hex_color::RUSSIAN_GREEN ) };
constexpr auto         RUSSIAN_VIOLET{                          from_hex( hex_color::RUSSIAN_VIOLET ) };
constexpr auto         RUST{                                    from_hex( hex_color::RUST ) };
constexpr auto         RUSTY_RED{                               from_hex( hex_color::RUSTY_RED ) };
constexpr auto         SACRAMENTO_STATE_GREEN{                  from_hex( hex_color::SACRAMENTO_STATE_GREEN ) };
constexpr auto         SADDLE_BROWN{                            from_hex( hex_color::SADDLE_BROWN ) };
constexpr auto         SAFETY_ORANGE_1{                         from_hex( hex_color::SAFETY_ORANGE_1 ) };
constexpr auto         SAFETY_ORANGE_2{                         from_hex( hex_color::SAFETY_ORANGE_2 ) };
constexpr auto         BLAZE_ORANGE{                            from_hex( hex_color::BLAZE_ORANGE ) };
constexpr auto         SAFETY_YELLOW{                           from_hex( hex_color::SAFETY_YELLOW ) };
constexpr auto         SAFFRON{                                 from_hex( hex_color::SAFFRON ) };
constexpr auto         SAGE{                                    from_hex( hex_color::SAGE ) };
constexpr auto         ST_PATRICKS_BLUE{                        from_hex( hex_color::ST_PATRICKS_BLUE ) };
constexpr auto         SALMON{                                  from_hex( hex_color::SALMON ) };
constexpr auto         SALMON_PINK{                             from_hex( hex_color::SALMON_PINK ) };
constexpr auto         SAND{                                    from_hex( hex_color::SAND ) };
constexpr auto         SAND_DUNE{                               from_hex( hex_color::SAND_DUNE ) };
constexpr auto         SANDY_BROWN{                             from_hex( hex_color::SANDY_BROWN ) };
constexpr auto         SAP_GREEN{                               from_hex( hex_color::SAP_GREEN ) };
constexpr auto         SAPPHIRE{                                from_hex( hex_color::SAPPHIRE ) };
constexpr auto         SAPPHIRE_BLUE{                           from_hex( hex_color::SAPPHIRE_BLUE ) };
constexpr auto         SAPPHIRE_CRAYOLA{                        from_hex( hex_color::SAPPHIRE_CRAYOLA ) };
constexpr auto         SATIN_SHEEN_GOLD{                        from_hex( hex_color::SATIN_SHEEN_GOLD ) };
constexpr auto         SCARLET{                                 from_hex( hex_color::SCARLET ) };
constexpr auto         SCHAUSS_PINK{                            from_hex( hex_color::SCHAUSS_PINK ) };
constexpr auto         SCHOOL_BUS_YELLOW{                       from_hex( hex_color::SCHOOL_BUS_YELLOW ) };
constexpr auto         SCREAMIN_GREEN{                          from_hex( hex_color::SCREAMIN_GREEN ) };
constexpr auto         SEA_GREEN{                               from_hex( hex_color::SEA_GREEN ) };
constexpr auto         SEA_GREEN_CRAYOLA{                       from_hex( hex_color::SEA_GREEN_CRAYOLA ) };
constexpr auto         SEAL_BROWN{                              from_hex( hex_color::SEAL_BROWN ) };
constexpr auto         SEASHELL{                                from_hex( hex_color::SEASHELL ) };
constexpr auto         SELECTIVE_YELLOW{                        from_hex( hex_color::SELECTIVE_YELLOW ) };
constexpr auto         SEPIA{                                   from_hex( hex_color::SEPIA ) };
constexpr auto         SHADOW{                                  from_hex( hex_color::SHADOW ) };
constexpr auto         SHADOW_BLUE{                             from_hex( hex_color::SHADOW_BLUE ) };
constexpr auto         SHAMROCK_GREEN{                          from_hex( hex_color::SHAMROCK_GREEN ) };
constexpr auto         SHEEN_GREEN{                             from_hex( hex_color::SHEEN_GREEN ) };
constexpr auto         SHIMMERING_BLUSH{                        from_hex( hex_color::SHIMMERING_BLUSH ) };
constexpr auto         SHINY_SHAMROCK{                          from_hex( hex_color::SHINY_SHAMROCK ) };
constexpr auto         SHOCKING_PINK{                           from_hex( hex_color::SHOCKING_PINK ) };
constexpr auto         SHOCKING_PINK_CRAYOLA{                   from_hex( hex_color::SHOCKING_PINK_CRAYOLA ) };
constexpr auto         SIENNA{                                  from_hex( hex_color::SIENNA ) };
constexpr auto         SILVER{                                  from_hex( hex_color::SILVER ) };
constexpr auto         SILVER_CRAYOLA{                          from_hex( hex_color::SILVER_CRAYOLA ) };
constexpr auto         SILVER_METALLIC{                         from_hex( hex_color::SILVER_METALLIC ) };
constexpr auto         SILVER_CHALICE{                          from_hex( hex_color::SILVER_CHALICE ) };
constexpr auto         SILVER_PINK{                             from_hex( hex_color::SILVER_PINK ) };
constexpr auto         SILVER_SAND{                             from_hex( hex_color::SILVER_SAND ) };
constexpr auto         SINOPIA{                                 from_hex( hex_color::SINOPIA ) };
constexpr auto         SIZZLING_RED{                            from_hex( hex_color::SIZZLING_RED ) };
constexpr auto         SIZZLING_SUNRISE{                        from_hex( hex_color::SIZZLING_SUNRISE ) };
constexpr auto         SKOBELOFF{                               from_hex( hex_color::SKOBELOFF ) };
constexpr auto         SKY_BLUE{                                from_hex( hex_color::SKY_BLUE ) };
constexpr auto         SKY_BLUE_CRAYOLA{                        from_hex( hex_color::SKY_BLUE_CRAYOLA ) };
constexpr auto         SKY_MAGENTA{                             from_hex( hex_color::SKY_MAGENTA ) };
constexpr auto         SLATE_BLUE{                              from_hex( hex_color::SLATE_BLUE ) };
constexpr auto         SLATE_GRAY{                              from_hex( hex_color::SLATE_GRAY ) };
constexpr auto         SLIMY_GREEN{                             from_hex( hex_color::SLIMY_GREEN ) };
constexpr auto         SMITTEN{                                 from_hex( hex_color::SMITTEN ) };
constexpr auto         SMOKY_BLACK{                             from_hex( hex_color::SMOKY_BLACK ) };
constexpr auto         SNOW{                                    from_hex( hex_color::SNOW ) };
constexpr auto         SOLID_PINK{                              from_hex( hex_color::SOLID_PINK ) };
constexpr auto         SONIC_SILVER{                            from_hex( hex_color::SONIC_SILVER ) };
constexpr auto         SPACE_CADET{                             from_hex( hex_color::SPACE_CADET ) };
constexpr auto         SPANISH_BISTRE{                          from_hex( hex_color::SPANISH_BISTRE ) };
constexpr auto         SPANISH_BLUE{                            from_hex( hex_color::SPANISH_BLUE ) };
constexpr auto         SPANISH_CARMINE{                         from_hex( hex_color::SPANISH_CARMINE ) };
constexpr auto         SPANISH_GRAY{                            from_hex( hex_color::SPANISH_GRAY ) };
constexpr auto         SPANISH_GREEN{                           from_hex( hex_color::SPANISH_GREEN ) };
constexpr auto         SPANISH_ORANGE{                          from_hex( hex_color::SPANISH_ORANGE ) };
constexpr auto         SPANISH_PINK{                            from_hex( hex_color::SPANISH_PINK ) };
constexpr auto         SPANISH_RED{                             from_hex( hex_color::SPANISH_RED ) };
constexpr auto         SPANISH_SKY_BLUE{                        from_hex( hex_color::SPANISH_SKY_BLUE ) };
constexpr auto         SPANISH_VIOLET{                          from_hex( hex_color::SPANISH_VIOLET ) };
constexpr auto         SPANISH_VIRIDIAN{                        from_hex( hex_color::SPANISH_VIRIDIAN ) };
constexpr auto         SPRING_BUD{                              from_hex( hex_color::SPRING_BUD ) };
constexpr auto         SPRING_FROST{                            from_hex( hex_color::SPRING_FROST ) };
constexpr auto         SPRING_GREEN{                            from_hex( hex_color::SPRING_GREEN ) };
constexpr auto         SPRING_GREEN_CRAYOLA{                    from_hex( hex_color::SPRING_GREEN_CRAYOLA ) };
constexpr auto         STAR_COMMAND_BLUE{                       from_hex( hex_color::STAR_COMMAND_BLUE ) };
constexpr auto         STEEL_BLUE{                              from_hex( hex_color::STEEL_BLUE ) };
constexpr auto         STEEL_PINK{                              from_hex( hex_color::STEEL_PINK ) };
constexpr auto         STEEL_TEAL{                              from_hex( hex_color::STEEL_TEAL ) };
constexpr auto         STIL_DE_GRAIN_YELLOW{                    from_hex( hex_color::STIL_DE_GRAIN_YELLOW ) };
constexpr auto         STRAW{                                   from_hex( hex_color::STRAW ) };
constexpr auto         STRAWBERRY{                              from_hex( hex_color::STRAWBERRY ) };
constexpr auto         STRAWBERRY_BLONDE{                       from_hex( hex_color::STRAWBERRY_BLONDE ) };
constexpr auto         SUGAR_PLUM{                              from_hex( hex_color::SUGAR_PLUM ) };
constexpr auto         SUNGLOW{                                 from_hex( hex_color::SUNGLOW ) };
constexpr auto         SUNRAY{                                  from_hex( hex_color::SUNRAY ) };
constexpr auto         SUNSET{                                  from_hex( hex_color::SUNSET ) };
constexpr auto         SUPER_PINK{                              from_hex( hex_color::SUPER_PINK ) };
constexpr auto         SWEET_BROWN{                             from_hex( hex_color::SWEET_BROWN ) };
constexpr auto         SYRACUSE_ORANGE{                         from_hex( hex_color::SYRACUSE_ORANGE ) };
constexpr auto         TAN{                                     from_hex( hex_color::TAN ) };
constexpr auto         TAN_CRAYOLA{                             from_hex( hex_color::TAN_CRAYOLA ) };
constexpr auto         TANGERINE{                               from_hex( hex_color::TANGERINE ) };
constexpr auto         TANGO_PINK{                              from_hex( hex_color::TANGO_PINK ) };
constexpr auto         TART_ORANGE{                             from_hex( hex_color::TART_ORANGE ) };
constexpr auto         TAUPE{                                   from_hex( hex_color::TAUPE ) };
constexpr auto         TAUPE_GRAY{                              from_hex( hex_color::TAUPE_GRAY ) };
constexpr auto         TEA_GREEN{                               from_hex( hex_color::TEA_GREEN ) };
constexpr auto         TEA_ROSE_1{                              from_hex( hex_color::TEA_ROSE_1 ) };
constexpr auto         TEA_ROSE_2{                              from_hex( hex_color::TEA_ROSE_2 ) };
constexpr auto         TEAL{                                    from_hex( hex_color::TEAL ) };
constexpr auto         TEAL_BLUE{                               from_hex( hex_color::TEAL_BLUE ) };
constexpr auto         TELEMAGENTA{                             from_hex( hex_color::TELEMAGENTA ) };
constexpr auto         TENNÉ_TAWNY{                             from_hex( hex_color::TENNÉ_TAWNY ) };
constexpr auto         TENNE_TAWNY{                             from_hex( hex_color::TENNE_TAWNY ) };
constexpr auto         TERRA_COTTA{                             from_hex( hex_color::TERRA_COTTA ) };
constexpr auto         THISTLE{                                 from_hex( hex_color::THISTLE ) };
constexpr auto         THULIAN_PINK{                            from_hex( hex_color::THULIAN_PINK ) };
constexpr auto         TICKLE_ME_PINK{                          from_hex( hex_color::TICKLE_ME_PINK ) };
constexpr auto         TIFFANY_BLUE{                            from_hex( hex_color::TIFFANY_BLUE ) };
constexpr auto         TIMBERWOLF{                              from_hex( hex_color::TIMBERWOLF ) };
constexpr auto         TITANIUM_YELLOW{                         from_hex( hex_color::TITANIUM_YELLOW ) };
constexpr auto         TOMATO{                                  from_hex( hex_color::TOMATO ) };
constexpr auto         TROPICAL_RAINFOREST{                     from_hex( hex_color::TROPICAL_RAINFOREST ) };
constexpr auto         TRUE_BLUE{                               from_hex( hex_color::TRUE_BLUE ) };
constexpr auto         TRYPAN_BLUE{                             from_hex( hex_color::TRYPAN_BLUE ) };
constexpr auto         TUFTS_BLUE{                              from_hex( hex_color::TUFTS_BLUE ) };
constexpr auto         TUMBLEWEED{                              from_hex( hex_color::TUMBLEWEED ) };
constexpr auto         TURQUOISE{                               from_hex( hex_color::TURQUOISE ) };
constexpr auto         TURQUOISE_BLUE{                          from_hex( hex_color::TURQUOISE_BLUE ) };
constexpr auto         TURQUOISE_GREEN{                         from_hex( hex_color::TURQUOISE_GREEN ) };
constexpr auto         TURTLE_GREEN{                            from_hex( hex_color::TURTLE_GREEN ) };
constexpr auto         TUSCAN{                                  from_hex( hex_color::TUSCAN ) };
constexpr auto         TUSCAN_BROWN{                            from_hex( hex_color::TUSCAN_BROWN ) };
constexpr auto         TUSCAN_RED{                              from_hex( hex_color::TUSCAN_RED ) };
constexpr auto         TUSCAN_TAN{                              from_hex( hex_color::TUSCAN_TAN ) };
constexpr auto         TUSCANY{                                 from_hex( hex_color::TUSCANY ) };
constexpr auto         TWILIGHT_LAVENDER{                       from_hex( hex_color::TWILIGHT_LAVENDER ) };
constexpr auto         TYRIAN_PURPLE{                           from_hex( hex_color::TYRIAN_PURPLE ) };
constexpr auto         UA_BLUE{                                 from_hex( hex_color::UA_BLUE ) };
constexpr auto         UA_RED{                                  from_hex( hex_color::UA_RED ) };
constexpr auto         ULTRAMARINE{                             from_hex( hex_color::ULTRAMARINE ) };
constexpr auto         ULTRAMARINE_BLUE{                        from_hex( hex_color::ULTRAMARINE_BLUE ) };
constexpr auto         ULTRA_PINK{                              from_hex( hex_color::ULTRA_PINK ) };
constexpr auto         ULTRA_RED{                               from_hex( hex_color::ULTRA_RED ) };
constexpr auto         UMBER{                                   from_hex( hex_color::UMBER ) };
constexpr auto         UNBLEACHED_SILK{                         from_hex( hex_color::UNBLEACHED_SILK ) };
constexpr auto         UNITED_NATIONS_BLUE{                     from_hex( hex_color::UNITED_NATIONS_BLUE ) };
constexpr auto         UNIVERSITY_OF_PENNSYLVANIA_RED{          from_hex( hex_color::UNIVERSITY_OF_PENNSYLVANIA_RED ) };
constexpr auto         UNMELLOW_YELLOW{                         from_hex( hex_color::UNMELLOW_YELLOW ) };
constexpr auto         UP_FOREST_GREEN{                         from_hex( hex_color::UP_FOREST_GREEN ) };
constexpr auto         UP_MAROON{                               from_hex( hex_color::UP_MAROON ) };
constexpr auto         UPSDELL_RED{                             from_hex( hex_color::UPSDELL_RED ) };
constexpr auto         URANIAN_BLUE{                            from_hex( hex_color::URANIAN_BLUE ) };
constexpr auto         USAFA_BLUE{                              from_hex( hex_color::USAFA_BLUE ) };
constexpr auto         UNITED_STATES_AIRFORCE_ACADEMY_BLUE{     from_hex( hex_color::UNITED_STATES_AIRFORCE_ACADEMY_BLUE ) };
constexpr auto         VAN_DYKE_BROWN{                          from_hex( hex_color::VAN_DYKE_BROWN ) };
constexpr auto         VANILLA{                                 from_hex( hex_color::VANILLA ) };
constexpr auto         VANILLA_ICE{                             from_hex( hex_color::VANILLA_ICE ) };
constexpr auto         VEGAS_GOLD{                              from_hex( hex_color::VEGAS_GOLD ) };
constexpr auto         VENETIAN_RED{                            from_hex( hex_color::VENETIAN_RED ) };
constexpr auto         VERDIGRIS{                               from_hex( hex_color::VERDIGRIS ) };
constexpr auto         VERMILION_1{                             from_hex( hex_color::VERMILION_2 ) };
constexpr auto         VERMILION_2{                             from_hex( hex_color::VERMILION_2 ) };
constexpr auto         VERONICA{                                from_hex( hex_color::VERONICA ) };
constexpr auto         VIOLET{                                  from_hex( hex_color::VIOLET ) };
constexpr auto         VIOLET_COLOR_WHEEL{                      from_hex( hex_color::VIOLET_COLOR_WHEEL ) };
constexpr auto         VIOLET_CRAYOLA{                          from_hex( hex_color::VIOLET_CRAYOLA ) };
constexpr auto         VIOLET_RYB{                              from_hex( hex_color::VIOLET_RYB ) };
constexpr auto         VIOLET_WEB{                              from_hex( hex_color::VIOLET_WEB ) };
constexpr auto         VIOLET_BLUE{                             from_hex( hex_color::VIOLET_BLUE ) };
constexpr auto         VIOLET_BLUE_CRAYOLA{                     from_hex( hex_color::VIOLET_BLUE_CRAYOLA ) };
constexpr auto         VIOLET_RED{                              from_hex( hex_color::VIOLET_RED ) };
constexpr auto         VIRIDIAN{                                from_hex( hex_color::VIRIDIAN ) };
constexpr auto         VIRIDIAN_GREEN{                          from_hex( hex_color::VIRIDIAN_GREEN ) };
constexpr auto         VIVID_BURGUNDY{                          from_hex( hex_color::VIVID_BURGUNDY ) };
constexpr auto         VIVID_SKY_BLUE{                          from_hex( hex_color::VIVID_SKY_BLUE ) };
constexpr auto         VIVID_TANGERINE{                         from_hex( hex_color::VIVID_TANGERINE ) };
constexpr auto         VIVID_VIOLET{                            from_hex( hex_color::VIVID_VIOLET ) };
constexpr auto         VOLT{                                    from_hex( hex_color::VOLT ) };
constexpr auto         WARM_BLACK{                              from_hex( hex_color::WARM_BLACK ) };
constexpr auto         WHEAT{                                   from_hex( hex_color::WHEAT ) };
constexpr auto         WHITE{                                   from_hex( hex_color::WHITE ) };
constexpr auto         WILD_BLUE_YONDER{                        from_hex( hex_color::WILD_BLUE_YONDER ) };
constexpr auto         WILD_ORCHID{                             from_hex( hex_color::WILD_ORCHID ) };
constexpr auto         WILD_STRAWBERRY{                         from_hex( hex_color::WILD_STRAWBERRY ) };
constexpr auto         WILD_WATERMELON{                         from_hex( hex_color::WILD_WATERMELON ) };
constexpr auto         WINDSOR_TAN{                             from_hex( hex_color::WINDSOR_TAN ) };
constexpr auto         WINE{                                    from_hex( hex_color::WINE ) };
constexpr auto         WINE_DREGS{                              from_hex( hex_color::WINE_DREGS ) };
constexpr auto         WINTER_SKY{                              from_hex( hex_color::WINTER_SKY ) };
constexpr auto         WINTERGREEN_DREAM{                       from_hex( hex_color::WINTERGREEN_DREAM ) };
constexpr auto         WISTERIA{                                from_hex( hex_color::WISTERIA ) };
constexpr auto         WOOD_BROWN{                              from_hex( hex_color::WOOD_BROWN ) };
constexpr auto         XANADU{                                  from_hex( hex_color::XANADU ) };
constexpr auto         XANTHIC{                                 from_hex( hex_color::XANTHIC ) };
constexpr auto         XANTHOUS{                                from_hex( hex_color::XANTHOUS ) };
constexpr auto         YALE_BLUE{                               from_hex( hex_color::YALE_BLUE ) };
constexpr auto         YELLOW{                                  from_hex( hex_color::YELLOW ) };
constexpr auto         YELLOW_CRAYOLA{                          from_hex( hex_color::YELLOW_CRAYOLA ) };
constexpr auto         YELLOW_MUNSELL{                          from_hex( hex_color::YELLOW_MUNSELL ) };
constexpr auto         YELLOW_NCS{                              from_hex( hex_color::YELLOW_NCS ) };
constexpr auto         YELLOW_PANTONE{                          from_hex( hex_color::YELLOW_PANTONE ) };
constexpr auto         YELLOW_PROCESS{                          from_hex( hex_color::YELLOW_PROCESS ) };
constexpr auto         YELLOW_RYB{                              from_hex( hex_color::YELLOW_RYB ) };
constexpr auto         YELLOW_GREEN{                            from_hex( hex_color::YELLOW_GREEN ) };
constexpr auto         YELLOW_GREEN_CRAYOLA{                    from_hex( hex_color::YELLOW_GREEN_CRAYOLA ) };
constexpr auto         YELLOW_GREEN_COLOR_WHEEL{                from_hex( hex_color::YELLOW_GREEN_COLOR_WHEEL ) };
constexpr auto         YELLOW_ORANGE{                           from_hex( hex_color::YELLOW_ORANGE ) };
constexpr auto         YELLOW_ORANGE_COLOR_WHEEL{               from_hex( hex_color::YELLOW_ORANGE_COLOR_WHEEL ) };
constexpr auto         YELLOW_SUNSHINE{                         from_hex( hex_color::YELLOW_SUNSHINE ) };
constexpr auto         YINMN_BLUE{                              from_hex( hex_color::YINMN_BLUE ) };
constexpr auto         ZAFFRE{                                  from_hex( hex_color::ZAFFRE ) };
constexpr auto         ZOMP{                                    from_hex( hex_color::ZOMP ) };
constexpr auto         PANTONE_448_C{                           from_hex( hex_color::PANTONE_448_C ) };
#endif //NAMED_COLORS_ENABLE_TUPLES