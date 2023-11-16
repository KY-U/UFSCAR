db.consultas.insert({
    data: '27-08-2019',
    paciente: [
        {
            cpf: '12345678911',
            nome: 'Joao Dois',
            nroufscar: '1234445678'
        }
    ],
    medico: 'Mani Moura',
    sintomas: ['dor cabeca', 'coriza', 'tosse'],
    diagnostico: ['gripe', 'enxaqueca'],
    exames:[ 
        { nomeexame: 'Raio X da Face', data: '1-1-2020'}, 
        { nomeexame: 'tipagem sanguinea', laboratorio: 'ufscarlab'}
    ],
    medicamentos:[
        { nome: 'dipirona', dosagem: '3xdia'}, 
        { nome: 'benegripe', dosagem: '1xsem'}
    ]
})

db.consultas.insert({
    data: '12-07-2019',
    paciente: [
        {
            cpf: '12345678911',
            nome: 'Joao Dois',
            nroufscar: '1234445678'
        }
    ],
    medico: 'Joao Saude',
    sintomas: ['dor peito', 'suor', 'tosse'],
    diagnostico: ['pneumonia', 'h1n1'],
    medicamentos: [
        { nome: 'dipirona', dosagem: '3xdia'}, 
        { nome: 'benegripe',dosagem: '1xsem'}
    ]
})