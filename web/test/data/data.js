const data = {
    website: "FER knjižara",

    basketsize: 0,

    categories_names: [
        "Udžbenici iz matematike",
        "Zbirke zadataka iz matematike",
        "Udžbenici iz elektrotehničkih predmeta",
        "Zbirke zadataka iz elektrotehničkih predmeta",
        "Udžbenici iz računarskih predmeta",
        "Zbirke zadataka iz računarskih predmeta",
        "Udžbenici i zbirke zadataka iz ostalih predmeta",
        "Bilježnice sa stranicama s crtama",
        "Bilježnice s kariranim stranicama",
        "Bilježnice s praznim stranicama",
    ],

    categories: {
        "Udžbenici iz matematike": [
            {
                name: "Matematička analiza 1",
                image: "matan1udz.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Matematička analiza 2",
                image: "matan2udz.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Matematička analiza 3",
                image: "matan3udz.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Linearna algebra",
                image: "linearnaudz.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Vjerojatnost i statistika",
                image: "visudz.png",
                amounts: [],
                price: 0,
            },
        ],

        "Zbirke zadataka iz matematike": [
            {
                name: "Matematička analiza 1: zbirka zadataka",
                image: "matan1zbirka.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Matematička analiza 2: zbirka zadataka",
                image: "matan2zbirka.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Matematička analiza 3: zbirka zadataka",
                image: "matan3zbirka.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Linearna algebra: zbirka zadataka (12€)",
                image: "linearnazbirka.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Vjerojatnost i statistika: zbirka zadataka",
                image: "viszbirka.png",
                amounts: [],
                price: 0,
            },
        ],

        "Udžbenici iz elektrotehničkih predmeta": [
            {
                name: "Osnove elektrotehnike",
                image: "osneleudz.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Električni krugovi",
                image: "elekruudz.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Elektronika 1",
                image: "el1udz.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Elektronika 2",
                image: "el2udz.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Signali i sustavi",
                image: "sisudz.png",
                amounts: [],
                price: 0,
            },
        ],

        "Zbirke zadataka iz elektrotehničkih predmeta": [
            {
                name: "Osnove elektrotehnike: zbirka zadataka",
                image: "osnelezbirka.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Električni krugovi: zbirka zadataka",
                image: "elekruzbirka.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Elektronika 1: zbirka zadataka",
                image: "el1zbirka.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Elektronika 2: zbirka zadataka",
                image: "el2zbirka.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Signali i sustavi: zbirka zadataka",
                image: "siszbirka.png",
                amounts: [],
                price: 0,
            },
        ],

        "Udžbenici iz računarskih predmeta": [
            {
                name: "Uvod u programiranje",
                image: "uproudz.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Objektno orijentirano programiranje",
                image: "oopudz.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Natjecateljsko programiranje",
                image: "natproudz.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Skriptni jezici",
                image: "skrjezudz.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Uvod u teoriju računarstva",
                image: "utrudz.png",
                amounts: [],
                price: 0,
            },
        ],

        "Zbirke zadataka iz računarskih predmeta": [
            {
                name: "Uvod u programiranje: zbirka zadataka",
                image: "uprozbirka.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Objektno orijentirano programiranje: zbirka zadataka",
                image: "oopzbirka.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Natjecateljsko programiranje: zbirka zadataka",
                image: "natprozbirka.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Skriptni jezici: zbirka zadataka",
                image: "skrjezzbirka.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Uvod u teoriju računarstva: zbirka zadataka",
                image: "utrzbirka.png",
                amounts: [],
                price: 0,
            },
        ],

        "Udžbenici i zbirke zadataka iz ostalih predmeta": [
            {
                name: "Inženjerska ekonomika 1",
                image: "inzeko1udz.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Inženjerska ekonomika 1: zbirka zadataka",
                image: "inzeko1zbirka.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Inženjerska ekonomika 2",
                image: "inzeko2udz.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Inženjerska ekonomika 2: zbirka zadataka",
                image: "inzeko2zbirka.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Korištenje operacijskog sustava Linux",
                image: "kosludz.png",
                amounts: [],
                price: 0,
            },
        ],

        "Bilježnice sa stranicama s crtama": [
            {
                name: "Bilježnica s crtama 25 listova",
                image: "biljcrte.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Bilježnica s crtama 30 listova",
                image: "biljcrte.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Bilježnica s crtama 35 listova",
                image: "biljcrte.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Bilježnica s crtama 40 listova",
                image: "biljcrte.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Bilježnica s crtama 45 listova",
                image: "biljcrte.png",
                amounts: [],
                price: 0,
            },
        ],

        "Bilježnice s kariranim stranicama": [
            {
                name: "Bilježnica karirana 25 listova",
                image: "biljkaro.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Bilježnica karirana 30 listova",
                image: "biljkaro.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Bilježnica karirana 35 listova",
                image: "biljkaro.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Bilježnica karirana 40 listova",
                image: "biljkaro.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Bilježnica karirana 45 listova",
                image: "biljkaro.png",
                amounts: [],
                price: 0,
            },
        ],

        "Bilježnice s praznim stranicama": [
            {
                name: "Bilježnica prazna 25 listova",
                image: "biljprazna.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Bilježnica prazna 30 listova",
                image: "biljprazna.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Bilježnica prazna 35 listova",
                image: "biljprazna.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Bilježnica prazna 40 listova",
                image: "biljprazna.png",
                amounts: [],
                price: 0,
            },

            {
                name: "Bilježnica prazna 45 listova",
                image: "biljprazna.png",
                amounts: [],
                price: 0,
            },
        ],
    },
};

module.exports = data;
