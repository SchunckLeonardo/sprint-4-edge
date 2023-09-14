# Projeto IoT - Detecção de Objetos com Arduino

## Descrição

Este projeto de IoT tem como objetivo detectar objetos próximos a um drone usando um sensor ultrassônico e fornecer feedback visual por meio de um LED indicador. O sistema envia dados sobre a distância medida para uma plataforma online (Tago.io) para posterior análise e visualização.

## Arquitetura Proposta

A arquitetura deste projeto envolve três componentes principais:

1. **Dispositivo IoT (Arduino):** O Arduino é responsável pela medição da distância usando um sensor ultrassônico, controle do LED e envio de dados para o Node-RED por meio de comunicação serial.

2. **Back-end (Node-RED):** O Node-RED atua como o intermediário que recebe os dados do Arduino, formata-os em um objeto JSON e os envia para a plataforma Tago.io por meio de MQTT. Também realiza verificações de integridade usando o HiveMQTT WebSocket Client.

3. **Front-end (Tago.io):** A plataforma Tago.io é usada para armazenar e visualizar os dados da distância medida. É possível criar painéis de controle personalizados para monitorar as informações em tempo real.

## Recursos Necessários

- **Dispositivo Arduino:** Um Arduino com sensor ultrassônico e LED indicador.
- **Biblioteca ArduinoJSON:** Uma biblioteca pra transformar os dados dos sensores em JSON.
- **Computador com Node-RED:** O Node-RED é usado para processar e encaminhar os dados do Arduino.
- **Broker MQTT:** Configurar um servidor MQTT para permitir a comunicação entre o Node-RED e a plataforma Tago.io.
- **Conta Tago.io:** Criar uma conta gratuita na plataforma Tago.io para armazenar e visualizar os dados.
- **HiveMQTT WebSocket Client:** Para realizar verificações de integridade na comunicação MQTT.

## Uso

1. **Configuração do Arduino:**
   - Conecte o sensor ultrassônico e o LED indicador ao Arduino.
   - Carregue o código do Arduino fornecido neste projeto para o dispositivo.

2. **Configuração do Node-RED:**
   - Importe o fluxo Node-RED fornecido e configure as portas e tópicos MQTT corretamente.

3. **Configuração da Tago.io:**
   - Crie uma conta na Tago.io, configure um dispositivo e defina as variáveis para armazenar os dados.

4. **Configuração do HiveMQTT WebSocket Client:**
   - Configure o HiveMQTT WebSocket Client para realizar verificações de integridade na comunicação MQTT, usando os mesmos tópicos MQTT configurados no Node-RED.

5. **Execução:**
   - Inicie o Node-RED e verifique se está recebendo os dados do Arduino.
   - Os dados sobre a distância medida e o estado do LED indicador serão transmitidos por meio de tópicos MQTT para a Tago.io.

6. **Monitoramento:**
   - Acesse o painel de controle na plataforma Tago.io para monitorar em tempo real as informações sobre a distância medida.

7. **Verificações de Integridade:**
   - Use o HiveMQTT WebSocket Client para realizar verificações periódicas na comunicação MQTT.
