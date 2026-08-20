<p align="center">
  <img src="https://raw.githubusercontent.com/n30nex/NeonPocketMC/main/branding/neonpocketmc-mark.png" alt="NeonPocketMC pocket mesh logo" width="140">
</p>

# NeonPocketMC-RC52-Headless

Screenless MeshCore BLE companion firmware for the Heltec RadioCore RC52-L62/SX1262.

> **RC52-L62 only. Do not flash RCC6, RC32, T114, or an RC52 with different radio hardware.**

**Guided install:** [flasher.canadaverse.org](https://flasher.canadaverse.org/)

## Pairing

The default Bluetooth pairing PIN is **`123456`**. Because this build has no display, it never generates a random on-screen PIN. A previously saved nonzero MeshCore BLE PIN still overrides the default.

## What is included

- Target: `heltec_rc52_headless_companion_radio_ble`
- Standard MeshCore BLE companion protocol for existing phone applications
- 200 contacts, 40 channels, and 128 queued companion frames
- RC52-L62 SX1262 mapping and the proven RC52 radio-power startup sequence
- DIO2 RF switching, DIO3 1.8 V TCXO, DC-DC mode, and RX boosted-gain fix
- Existing MeshCore identity, contacts, channels, preferences, bootloader, and SoftDevice are preserved by application-only UF2 updates
- No TFT initialization, framebuffer, Web/AP, USB companion, repeater, or room-server behavior

The firmware is based on the current NeonPocketMC RC52 source, including the MeshCore 1.17 RX gain correction. The TFT RC52 companion remains a separate product at [NeonPocketMC-RC52](https://github.com/n30nex/NeonPocketMC-RC52).

## Flashing

Use the guided flasher or follow [docs/FLASHING.md](docs/FLASHING.md). Release UF2 files are application-only and start at `0x26000`. Never erase or replace the bootloader or SoftDevice.

## Build verification

GitHub Actions:

1. runs the upstream native tests;
2. builds the exact headless RC52 target;
3. verifies the UF2 nRF52840 family and `0x26000` application address;
4. regression-builds the TFT RC52 companion and Heltec T114 BLE companion; and
5. publishes exact `.uf2`, `.hex`, checksums, and UF2 metadata.

## License

This is a derivative of [MeshCore](https://github.com/meshcore-dev/MeshCore). Preserve the upstream and third-party license notices when redistributing source or binaries. See [license.txt](license.txt).
